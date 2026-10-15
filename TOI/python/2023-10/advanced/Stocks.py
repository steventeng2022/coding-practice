# 1-股票交易 | 2023/10/23~2023/10/27 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Stocks.pdf
import sys
from heapq import heappush, heappop

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, k = next(it), next(it)
    answer = [-1] * n
    waiting = []
    for i in range(n):
        price = next(it)
        while waiting and waiting[0][0] <= price:
            _, bought = heappop(waiting)
            answer[bought] = i + 1
        heappush(waiting, (price + k, i))
    print(*answer)

if __name__ == '__main__':
    main()
