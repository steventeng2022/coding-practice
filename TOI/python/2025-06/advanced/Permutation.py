# 3-排列順序 | 2025/06/09~2025/06/13 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Permutation.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    perm = list(it)
    mod = 1_000_000_007
    fact = [1] * (m + 1)
    for i in range(1, m + 1):
        fact[i] = fact[i - 1] * i % mod
    # P(m-i-1,n-i-1) 的分母階乘永遠是 (m-n)!。
    inverse = pow(fact[m - n], mod - 2, mod)
    bit = [0] * (m + 1)
    answer = 0
    for i, value in enumerate(perm):
        used, p = 0, value
        while p:
            used += bit[p]
            p -= p & -p
        smaller = value - 1 - used
        answer = (answer + smaller * fact[m - i - 1] * inverse) % mod
        p = value
        while p <= m:
            bit[p] += 1
            p += p & -p
    print(answer)

if __name__ == '__main__':
    main()
