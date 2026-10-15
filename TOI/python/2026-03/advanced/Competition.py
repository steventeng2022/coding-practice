# 3-三仙鬥法 | 2026/03/16~2026/03/20 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Competition.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    rounds = next(it)
    answer = []
    for _ in range(rounds):
        a, b, c = next(it) & 1, next(it) & 1, next(it) & 1
        if a == b == c:
            answer.append('A B C')
        elif a == b:
            answer.append('C')
        elif b == c:
            answer.append('A')
        else:
            answer.append('B')
    print('\n'.join(answer))

if __name__ == '__main__':
    main()
