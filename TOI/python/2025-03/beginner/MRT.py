# 2-捷運 | 2025/03/17~2025/03/21 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/MRT.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    total = sum(it)
    rate = 85 if n >= 41 else 90 if n >= 21 else 95 if n >= 11 else 100
    print(min(1200, (total * rate + 50) // 100))

if __name__ == '__main__':
    main()
