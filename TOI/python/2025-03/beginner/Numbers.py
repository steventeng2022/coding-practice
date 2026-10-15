# 3-找數字 | 2025/03/17~2025/03/21 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Numbers.pdf
import sys
from math import isqrt

def main():
    n = int(sys.stdin.buffer.read())
    def prime(x):
        if x < 2: return False
        if x % 2 == 0: return x == 2
        return all(x % d for d in range(3, isqrt(x) + 1, 2))
    p = n + 1
    while not prime(p):
        p += 1
    square = (isqrt(n) + 1) ** 2
    left, right = 0, 1
    while right ** 3 <= n:
        right *= 2
    while left + 1 < right:
        mid = (left + right) // 2
        if mid ** 3 <= n:
            left = mid
        else:
            right = mid
    print(p, square, right ** 3)

if __name__ == '__main__':
    main()
