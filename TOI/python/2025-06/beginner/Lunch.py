# 2-午餐 | 2025/06/09~2025/06/13 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Lunch.pdf
import sys

def main():
    data = sys.stdin.buffer.read().split()
    r, c = int(data[0]), int(data[1])
    target = data[2 + r * c]
    answer = []
    for i, name in enumerate(data[2:2 + r * c]):
        if name == target:
            answer.append(f'{i // c + 1} {i % c + 1}')
    print('\n'.join(answer) if answer else '0 0')

if __name__ == '__main__':
    main()
