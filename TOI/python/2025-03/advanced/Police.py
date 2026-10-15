# 3-取締違規 | 2025/03/17~2025/03/21 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Police.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    delta = [0] * (m + 2)
    for _ in range(n):
        count, left, right = next(it), next(it), next(it)
        delta[left] += count
        delta[right + 1] -= count
    current = best = 0
    position = 0
    for i in range(m + 1):
        current += delta[i]
        if current > best:
            best, position = current, i
    print(position, best)

if __name__ == '__main__':
    main()
