# 2-水管 | 2025/04/28~2025/05/02 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Pipe.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    a = [next(it) for _ in range(n)]
    b = list(it)
    dp = [0] * (n + 1)
    for x in a:
        diagonal = 0
        for j, y in enumerate(b, 1):
            old = dp[j]
            connect = diagonal + min(x, y)
            dp[j] = max(connect, dp[j], dp[j - 1])
            diagonal = old
    print(dp[n])

if __name__ == '__main__':
    main()
