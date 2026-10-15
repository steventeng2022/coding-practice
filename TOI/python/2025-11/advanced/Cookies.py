# 2-餅乾促銷 | 2025/11/10~2025/11/14 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Cookies.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, goal = next(it), next(it)
    offers = [(next(it), next(it)) for _ in range(n)]
    bound = goal - 1 + max(a + b for a, b in offers)
    inf = 10 ** 18
    dp = [inf] * (bound + 1)
    dp[0] = 0
    for cost, gift in offers:
        size = cost + gift
        for count in range(size, bound + 1):
            candidate = dp[count - size] + cost
            if candidate < dp[count]:
                dp[count] = candidate
    print(min(dp[goal:]))

if __name__ == '__main__':
    main()
