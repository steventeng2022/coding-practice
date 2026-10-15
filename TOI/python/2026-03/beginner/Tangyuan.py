# 3-湯圓 | 2026/03/16~2026/03/20 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tangyuan.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    sesame = peanut = 0
    for _ in range(n):
        sesame += next(it)
        peanut += next(it)
    for total in (sesame, peanut):
        boxes = (total + 9) // 10
        print(boxes, boxes * 10 - total)

if __name__ == '__main__':
    main()
