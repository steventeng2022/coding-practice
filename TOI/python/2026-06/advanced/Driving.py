# 1-駕駛汽車 | 2026/06/8~2026/06/12 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Driving.pdf
import sys
from collections import deque
from array import array

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    m, n = next(it), next(it)
    grid = array('b', it)
    size = m * n
    inf = 2_000_000_000
    distance = array('i', [inf]) * (size * 4)
    # 所有邊權在 0..10；循環桶數必須比最大邊權大。
    buckets = [deque() for _ in range(11)]
    for d in range(4):
        distance[d] = 0
        buckets[0].append(d)
    pending, current = 4, 0
    while pending:
        bucket = buckets[current % 11]
        if not bucket:
            current += 1
            continue
        state = bucket.popleft()
        pending -= 1
        if distance[state] != current:
            continue
        pos, previous = divmod(state, 4)
        if pos == size - 1:
            print(current)
            return
        r, c = divmod(pos, n)
        for d, allowed, to in ((0, c + 1 < n, pos + 1),
                               (1, r + 1 < m, pos + n),
                               (2, c > 0, pos - 1),
                               (3, r > 0, pos - n)):
            if not allowed or grid[to] < 0:
                continue
            nd = current + grid[to] + (d != previous)
            ns = to * 4 + d
            if nd < distance[ns]:
                distance[ns] = nd
                buckets[nd % 11].append(ns)
                pending += 1
    print(-1)

if __name__ == '__main__':
    main()
