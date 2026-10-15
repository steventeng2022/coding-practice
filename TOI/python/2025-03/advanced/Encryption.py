# 1-加密系統 | 2025/03/17~2025/03/21 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Encryption.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    t = next(it)
    answer = []
    for _ in range(t):
        a, b = next(it), next(it)
        difference = a - b
        if difference == 0:
            answer.append('0 0')
        else:
            highest = 1 << (difference.bit_length() - 1)
            answer.append(f'{difference} {2 * highest - difference}')
    print('\n'.join(answer))

if __name__ == '__main__':
    main()
