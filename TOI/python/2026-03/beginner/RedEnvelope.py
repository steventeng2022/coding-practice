# 1-紅包 | 2026/03/16~2026/03/20 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/RedEnvelope.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    answer = 0
    for _ in range(n):
        answer += next(it) * 100 + next(it) * 500 + next(it) * 1000
    print(answer)

if __name__ == '__main__':
    main()
