"""Compile standalone answers and run the checked-in official examples."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[1]

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--language', choices=('python', 'cpp', 'both'), default='both')
    parser.add_argument('--compiler', default=os.environ.get('CXX', 'g++'))
    parser.add_argument('--all-reference', action='store_true')
    args = parser.parse_args()
    tasks = json.loads((ROOT / 'manifest.json').read_text(encoding='utf-8'))
    samples = json.loads((ROOT / 'tests/samples.json').read_text(encoding='utf-8'))
    passed = failed = compiled = 0
    with tempfile.TemporaryDirectory(prefix='.toi-check-', dir=ROOT / 'tests') as directory:
        for index, task in enumerate(tasks):
            cases = samples.get(task['id'], [])
            commands = []
            if args.language in ('cpp', 'both') and task['cpp'] and (cases or args.all_reference):
                exe = Path(directory) / (f'{index}.exe' if os.name == 'nt' else str(index))
                command = [args.compiler, '-std=gnu++17', '-O2', str(ROOT / task['cpp']), '-o', str(exe)]
                try:
                    result = subprocess.run(command, capture_output=True, text=True, timeout=120)
                    if result.returncode:
                        print(f'COMPILE FAILED: {task["id"]}\n{result.stderr}')
                        failed += 1
                        continue
                except (OSError, subprocess.TimeoutExpired) as error:
                    print(f'COMPILE FAILED: {task["id"]}: {error}')
                    failed += 1
                    continue
                compiled += 1
                commands.append(('cpp', [str(exe)]))
            if args.language in ('python', 'both') and task['python']:
                commands.append(('python', [sys.executable, str(ROOT / task['python'])]))
            for case in cases:
                for language, command in commands:
                    try:
                        result = subprocess.run(command, input=case['input'], capture_output=True,
                                                text=True, encoding='utf-8', timeout=15)
                        ok = result.returncode == 0 and result.stdout.split() == case['output'].split()
                        detail = result.stderr or result.stdout
                    except (OSError, subprocess.TimeoutExpired) as error:
                        ok, detail = False, str(error)
                    if ok:
                        passed += 1
                    else:
                        failed += 1
                        print(f'FAILED: {task["id"]} sample {case["number"]} {language}\n{detail}')
    print(f'{compiled} compiled, {passed} sample executions passed, {failed} failures')
    return bool(failed)

if __name__ == '__main__':
    raise SystemExit(main())
