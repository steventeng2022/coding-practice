# 1-雷射探測 | 2026/06/8~2026/06/12 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Laser.pdf
import sys

def main():
    data = sys.stdin.buffer.read().split()
    n, m = map(int, data[:2])
    grid = data[2:]
    # 方向依序為右、下、左、上；每格用四個位元記錄方向。
    seen = bytearray(n * m)
    dr, dc = (0, 1, 0, -1), (1, 0, -1, 0)
    r = c = direction = answer = 0
    while 0 <= r < n and 0 <= c < m and grid[r][c] != 35:
        pos = r * m + c
        mask = 1 << direction
        if seen[pos] & mask:
            break
        if not seen[pos]:
            answer += 1
        seen[pos] |= mask
        r += dr[direction]
        c += dc[direction]
        if 0 <= r < n and 0 <= c < m:
            if grid[r][c] == 82:  # R: ／
                direction ^= 3
            elif grid[r][c] == 76:  # L: ＼
                direction ^= 1
    print(answer)

if __name__ == '__main__':
    main()
