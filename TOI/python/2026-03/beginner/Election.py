# 2-選舉 | 2026/03/16~2026/03/20 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Election.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    k = next(it)
    a = b = 0
    for _ in range(k):
        n, m, x = next(it), next(it), next(it)
        if n > m:
            a += x
        elif m > n:
            b += x
    print(1, a) if a > b else print(2, b)

if __name__ == '__main__':
    main()
