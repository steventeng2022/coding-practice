# 2-鬆餅 | 2026/05/04~2026/05/08 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Waffle.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    times = [next(it), next(it)]
    m = next(it)
    finish = [0, 0]
    for _ in range(m):
        kind = next(it) - 1
        oven = 0 if finish[0] <= finish[1] else 1
        finish[oven] += times[kind]
    print(max(finish))

if __name__ == '__main__':
    main()
