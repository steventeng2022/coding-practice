# 3-整數分拆 | 2025/09/29~2025/10/03 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/partition.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    t = next(it)
    mod = 1_000_000_007
    answer = []
    for _ in range(t):
        x = next(it)
        if x <= 3:
            best = x
        else:
            power, remainder = divmod(x, 3)
            if remainder == 1:
                best = 4 * pow(3, power - 1, mod) % mod
            elif remainder == 2:
                best = 2 * pow(3, power, mod) % mod
            else:
                best = pow(3, power, mod)
        answer.append(str(best))
    print('\n'.join(answer))

if __name__ == '__main__':
    main()
