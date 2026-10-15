# 1-樂透 | 2025/11/10~2025/11/14 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Lotto.pdf
import sys

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    ticket, numbers = set(data[:6]), set(data[6:12])
    matched, special = len(ticket & numbers), data[12] in ticket
    prizes = {(6, False): 'A', (6, True): 'A', (5, True): 'B', (5, False): 'C',
              (4, True): 'D', (4, False): 'E', (3, True): 'F', (2, True): 'G',
              (3, False): 'H'}
    print(prizes.get((matched, special), 'X'))

if __name__ == '__main__':
    main()
