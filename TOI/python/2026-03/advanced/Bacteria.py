# 1-細菌繁殖 | 2026/03/16~2026/03/20 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Bacteria.pdf
import sys
from collections import deque

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    m, n, k, time = next(it), next(it), next(it), next(it)
    grid = list(it)
    starts = [0] * k
    for pos, who in enumerate(grid):
        if who > 0:
            starts[who - 1] = pos
    queue = deque(starts)
    counts = [1] * k
    elapsed = 0
    while queue and elapsed < time:
        for _ in range(len(queue)):
            pos = queue.popleft()
            r, c = divmod(pos, n)
            who = grid[pos]
            for allowed, to in ((r > 0, pos - n), (r + 1 < m, pos + n),
                                (c > 0, pos - 1), (c + 1 < n, pos + 1)):
                if allowed and grid[to] == 0:
                    grid[to] = who
                    counts[who - 1] += 1
                    queue.append(to)
        elapsed += 1
    print(*counts)

if __name__ == '__main__':
    main()
