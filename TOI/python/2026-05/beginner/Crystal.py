# 1-水晶共鳴 | 2026/05/04~2026/05/08 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Crystal.pdf
import sys
from itertools import groupby

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    next(it)
    print(' '.join(str(sum(1 for _ in group)) for _, group in groupby(it)))

if __name__ == '__main__':
    main()
