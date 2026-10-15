# 1-島嶼 | 2025/06/09~2025/06/13 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Island.pdf
import sys
from collections import deque

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    grid = list(it)
    start = grid.index(1)
    def neighbors(p):
        r, c = divmod(p, m)
        if r: yield p - m
        if r + 1 < n: yield p + m
        if c: yield p - 1
        if c + 1 < m: yield p + 1
    queue = deque([start])
    grid[start] = -1
    island = []
    while queue:
        p = queue.popleft()
        island.append(p)
        for to in neighbors(p):
            if grid[to] == 1:
                grid[to] = -1
                queue.append(to)
    queue.extend(island)
    distance = 0
    while queue:
        for _ in range(len(queue)):
            p = queue.popleft()
            for to in neighbors(p):
                if grid[to] == 1:
                    print(distance)
                    return
                if grid[to] == 0:
                    grid[to] = -1
                    queue.append(to)
        distance += 1
    print(-1)

if __name__ == '__main__':
    main()
