# 1-串燒 | 2025/12/22~2025/12/26 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/BBQ.pdf
import sys
from collections import Counter

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    delivered = Counter(next(it) for _ in range(n))
    ordered = Counter()
    for _ in range(m):
        for _ in range(next(it)):
            ordered[next(it)] += 1
    print(sum((ordered - delivered).values()), sum((delivered - ordered).values()))

if __name__ == '__main__':
    main()
