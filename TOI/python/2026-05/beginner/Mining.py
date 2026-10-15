# 3-礦業調度 | 2026/05/04~2026/05/08 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Mining.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    values = sorted((max(0, next(it) - i) for i in range(n)), reverse=True)
    values.append(0)
    answer = 0
    for i in range(n):
        high, low, width = values[i], values[i + 1], i + 1
        count = (high - low) * width
        if m >= count:
            answer += (high + low + 1) * (high - low) // 2 * width
            m -= count
        else:
            levels, extra = divmod(m, width)
            answer += (2 * high - levels + 1) * levels // 2 * width
            answer += extra * (high - levels)
            break
    print(answer)

if __name__ == '__main__':
    main()
