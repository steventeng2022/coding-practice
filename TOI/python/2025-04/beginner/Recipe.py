# 1-食譜換算 | 2025/04/28~2025/05/02 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Recipe.pdf
import sys

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    n, portions = data[:2]
    wanted = data[n + 2]
    print(*((weight * wanted + portions - 1) // portions for weight in data[2:n + 2]))

if __name__ == '__main__':
    main()
