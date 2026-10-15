# 1-指數 | 2025/09/29~2025/10/03 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/power.pdf
import sys

def main():
    n, limit = map(int, sys.stdin.buffer.read().split())
    value = n
    answer = []
    while value <= limit:
        answer.append(str(value))
        value *= n
    print('\n'.join(answer))

if __name__ == '__main__':
    main()
