# 1-巫師帽 | 2025/11/10~2025/11/14 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Hat.pdf
import sys
from collections import Counter

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    next(it)
    print(sum((count + x) // (x + 1) * (x + 1) for x, count in Counter(it).items()))

if __name__ == '__main__':
    main()
