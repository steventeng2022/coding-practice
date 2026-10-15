# 3-茶店 | 2025/09/29~2025/10/03 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/tea.pdf
import sys

def main():
    price, degree, hour, cold = map(int, sys.stdin.buffer.read().split())
    if (degree <= 15 and cold == 1) or (degree >= 30 and cold == 0):
        price -= 5
    if 7 <= hour < 10 or 14 <= hour < 16:
        price -= 5
    print(price)

if __name__ == '__main__':
    main()
