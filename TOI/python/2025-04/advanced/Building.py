# 1-建築物拆除 | 2025/04/28~2025/05/02 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Building.pdf
import sys
from functools import cmp_to_key

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    buildings = [(next(it), next(it)) for _ in range(n)]
    def compare(x, y):
        left, right = x[0] * y[1], y[0] * x[1]
        return (right > left) - (right < left)
    buildings.sort(key=cmp_to_key(compare))
    remaining = sum(a for a, _ in buildings)
    answer = 0
    for penalty, duration in buildings:
        answer += remaining * duration
        remaining -= penalty
    print(answer)

if __name__ == '__main__':
    main()
