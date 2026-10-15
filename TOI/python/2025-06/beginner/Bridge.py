# 3-橋牌 | 2025/06/09~2025/06/13 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Bridge.pdf
import sys

def main():
    cards = sys.stdin.buffer.read().split()
    counts = dict.fromkeys(b'SHDC', 0)
    points = dict(zip(b'AKQJ', (4, 3, 2, 1)))
    score = 0
    for card in cards:
        counts[card[0]] += 1
        score += points.get(card[1], 0)
    print(*(counts[s] for s in b'SHDC'))
    print(score)

if __name__ == '__main__':
    main()
