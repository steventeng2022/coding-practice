# 2-像素圖放大 | 2026/06/8~2026/06/12 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Pixel.pdf
import sys

def main():
    it = iter(sys.stdin.buffer.read().split())
    n, m, p, q = (int(next(it)) for _ in range(4))
    write = sys.stdout.write
    for _ in range(n):
        row = ' '.join(x.decode() for x in (next(it) for _ in range(m)) for _ in range(q))
        write((row + '\n') * p)

if __name__ == '__main__':
    main()
