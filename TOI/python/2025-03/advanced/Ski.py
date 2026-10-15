# 2-滑雪場 | 2025/03/17~2025/03/21 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Ski.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, low, high = next(it), next(it), next(it)
    bad = last_low = last_high = -1
    answer = 0
    for i in range(n):
        x = next(it)
        if x < low or x > high:
            bad = i
        if x == low:
            last_low = i
        if x == high:
            last_high = i
        answer += max(0, min(last_low, last_high) - bad)
    print(answer)

if __name__ == '__main__':
    main()
