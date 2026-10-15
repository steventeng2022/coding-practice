# 3-塗鴉連線 | 2025/12/22~2025/12/26 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Doodle.pdf
import sys
from collections import deque

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    rows, cols = next(it), next(it)
    grid = list(it)
    distance = [-1] * (rows * cols)
    distance[0] = 1
    queue = deque([0])
    while queue:
        p = queue.popleft()
        if p == len(grid) - 1:
            print(distance[p])
            return
        r, c = divmod(p, cols)
        for allowed, to in ((r > 0, p - cols), (r + 1 < rows, p + cols),
                            (c > 0, p - 1), (c + 1 < cols, p + 1)):
            if allowed and grid[to] and distance[to] < 0:
                distance[to] = distance[p] + 1
                queue.append(to)

if __name__ == '__main__':
    main()
