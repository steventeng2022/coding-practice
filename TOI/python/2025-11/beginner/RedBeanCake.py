# 3-紅豆餅 | 2025/11/10~2025/11/14 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/RedBeanCake.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    counts = [0] * 6
    for _ in range(n):
        counts[next(it)] += 1
    drinks, cakes = counts[0], sum(counts[1:])
    pairs = min(drinks, cakes)
    price = pairs * 59 + (drinks - pairs) * 50 + (cakes - pairs) * 20
    print(*counts, price)

if __name__ == '__main__':
    main()
