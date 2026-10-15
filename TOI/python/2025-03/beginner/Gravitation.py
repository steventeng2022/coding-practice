# 1-萬有引力 | 2025/03/17~2025/03/21 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Gravitation.pdf
import sys

def main():
    m1, m2, r = map(int, sys.stdin.buffer.read().split())
    print(6 * m1 * m2 // (r * r))

if __name__ == '__main__':
    main()
