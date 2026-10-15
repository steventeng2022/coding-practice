# 2-提拉米蘇 | 2025/12/22~2025/12/26 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Tiramisu.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    m, n = next(it), next(it)
    def area2(count):
        x, y = next(it), next(it)
        area = 0
        for _ in range(count - 1):
            nx, ny = next(it), next(it)
            area += (nx - x) * (ny + y)
            x, y = nx, ny
        return area
    top = area2(m)
    bottom = area2(n)
    print(top - bottom)

if __name__ == '__main__':
    main()
