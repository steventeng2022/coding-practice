# 2-社團 | 2025/12/22~2025/12/26 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Club.pdf
import sys

def main():
    it = iter(sys.stdin.buffer.read().split())
    n, m = int(next(it)), int(next(it))
    names = [next(it) for _ in range(m)]
    counts = dict.fromkeys(names, 0)
    for _ in range(n):
        for name in {next(it), next(it), next(it)}:
            counts[name] += 1
    print('\n'.join(name.decode() + ' ' + str(counts[name]) for name in names))

if __name__ == '__main__':
    main()
