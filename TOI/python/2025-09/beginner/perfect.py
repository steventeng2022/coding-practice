# 2-完美數 | 2025/09/29~2025/10/03 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/perfect.pdf
import sys
from math import isqrt

def main():
    n = int(sys.stdin.buffer.read())
    total = 1
    for divisor in range(2, isqrt(n) + 1):
        if n % divisor == 0:
            total += divisor
            other = n // divisor
            if other != divisor:
                total += other
    print(total)
    print('perfect' if total == n else 'not perfect')

if __name__ == '__main__':
    main()
