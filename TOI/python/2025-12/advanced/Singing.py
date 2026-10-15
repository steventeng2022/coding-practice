# 3-唱歌對決 | 2025/12/22~2025/12/26 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Singing.pdf
import sys
from bisect import bisect_left

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    points = sorted(((next(it), next(it)) for _ in range(n)), reverse=True)
    ys = sorted({y for _, y in points})
    rank = {y: i + 1 for i, y in enumerate(ys)}
    bit = [0] * (len(ys) + 1)
    def add(p, delta):
        while p < len(bit):
            bit[p] += delta
            p += p & -p
    def prefix(p):
        result = 0
        while p:
            result += bit[p]
            p -= p & -p
        return result
    for _, y in points:
        add(rank[y], 1)
    right, answer = n - 1, 0
    for left in range(n):
        if left >= right:
            break
        x, y = points[left]
        add(rank[y], -1)
        while left < right and x + points[right][0] < 0:
            add(rank[points[right][1]], -1)
            right -= 1
        if left < right:
            answer += right - left - prefix(bisect_left(ys, -y))
    print(answer)

if __name__ == '__main__':
    main()
