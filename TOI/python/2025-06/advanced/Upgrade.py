# 2-角色升級 | 2025/06/09~2025/06/13 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Upgrade.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    attack, defense, n = next(it), next(it), next(it)
    delta = [next(it) - next(it) for _ in range(n)]
    half = n // 2
    sums = {attack - defense}
    for d in delta[:half]:
        sums |= {s + d for s in sums}
    def search(i, total):
        if i == n:
            return -total in sums
        return search(i + 1, total) or search(i + 1, total + delta[i])
    print(int(search(half, 0)))

if __name__ == '__main__':
    main()
