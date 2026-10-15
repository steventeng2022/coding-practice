# 2-試算表 | 2025/09/29~2025/10/03 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/sheet.pdf
import sys
from collections import deque

def main():
    data = sys.stdin.buffer.read().split()
    m, n = int(data[0]), int(data[1])
    cells = data[2:]
    count = m * n
    values, degree = [0] * count, [0] * count
    dependents = [[] for _ in range(count)]
    mod = 1_000_000_007
    for i, cell in enumerate(cells):
        terms = cell[1:].split(b'+') if cell.startswith(b'=') else [cell]
        for term in terms:
            if 65 <= term[0] <= 90:
                source = (int(term[1:]) - 1) * n + term[0] - 65
                degree[i] += 1
                dependents[source].append(i)
            else:
                values[i] += int(term)
    queue = deque(i for i in range(count) if degree[i] == 0)
    while queue:
        i = queue.popleft()
        values[i] %= mod
        for j in dependents[i]:
            values[j] = (values[j] + values[i]) % mod
            degree[j] -= 1
            if degree[j] == 0:
                queue.append(j)
    output = ['ERROR' if degree[i] else str(values[i]) for i in range(count)]
    print('\n'.join(' '.join(output[r * n:(r + 1) * n]) for r in range(m)))

if __name__ == '__main__':
    main()
