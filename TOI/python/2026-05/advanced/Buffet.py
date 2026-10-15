# 2-吃自助餐 | 2026/05/04~2026/05/08 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Buffet.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, budget, limit = next(it), next(it), next(it)
    global_dp = [0] * (budget + 1)
    for _ in range(n):
        m = next(it)
        # dp[k][p]: 此區最多選 k 道、總花費至多 p 時的最佳滿意度。
        cap = min(m, limit)
        dp = [global_dp.copy() for _ in range(cap + 1)]
        for j in range(m):
            cost, value = next(it), next(it)
            for k in range(cap, 0, -1):
                target, source = dp[k], dp[k - 1]
                for p in range(budget, cost - 1, -1):
                    candidate = source[p - cost] + value
                    if candidate > target[p]:
                        target[p] = candidate
        global_dp = dp[cap]
    print(global_dp[budget])

if __name__ == '__main__':
    main()
