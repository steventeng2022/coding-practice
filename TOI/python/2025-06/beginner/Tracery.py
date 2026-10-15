# 1-窗花 | 2025/06/09~2025/06/13 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Tracery.pdf
import sys

def main():
    data = sys.stdin.buffer.read().split()
    w, h = int(data[0]), int(data[1])
    # cin >> char 也接受不帶空白的輸入，因此把字元逐一展開。
    chars = list(b''.join(data[2:]).decode())
    rows = []
    for i in range(h):
        row = chars[i * w:(i + 1) * w]
        rows.append(' '.join(row + row[::-1]))
    print('\n'.join(rows + rows[::-1]))

if __name__ == '__main__':
    main()
