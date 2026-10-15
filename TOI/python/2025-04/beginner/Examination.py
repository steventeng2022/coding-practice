# 2-學測 | 2025/04/28~2025/05/02 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Examination.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    scores = [next(it) for _ in range(6)]
    answer = []
    for score in scores:
        standards = [next(it) for _ in range(5)]
        result = 'X' if score == 0 else 'F'
        if score:
            for i, threshold in enumerate(standards):
                if score >= threshold:
                    result = chr(65 + i)
                    break
        answer.append(result)
    print('\n'.join(answer))

if __name__ == '__main__':
    main()
