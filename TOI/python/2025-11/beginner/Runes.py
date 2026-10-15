# 2-符文 | 2025/11/10~2025/11/14 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Runes.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    text = [next(it) for _ in range(n)]
    pattern = list(it)
    failure = [0] * m
    j = 0
    for i in range(1, m):
        while j and pattern[i] != pattern[j]:
            j = failure[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
        failure[i] = j
    j = 0
    for i, value in enumerate(text):
        while j and value != pattern[j]:
            j = failure[j - 1]
        if value == pattern[j]:
            j += 1
        if j == m:
            print(i - m + 2)
            return
    print('not found')

if __name__ == '__main__':
    main()
