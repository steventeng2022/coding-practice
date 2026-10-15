# 3-地底寶藏 | 2025/04/28~2025/05/02 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/TreasureBox.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    next(it)
    boxes = list(it)
    minimum = min(boxes)
    positions = [i for i, value in enumerate(boxes) if value == minimum]
    index = positions[-1] - minimum if len(positions) > 1 else positions[0] + minimum
    y = boxes[index]
    print(boxes[y - 1])

if __name__ == '__main__':
    main()
