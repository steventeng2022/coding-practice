# 1-片段排序 | 2025/09/29~2025/10/03 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/cut.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(it)
    a = [next(it) for _ in range(n)]
    target = {value: i for i, value in enumerate(it)}
    print(sum(target[a[i]] != target[a[i - 1]] + 1 for i in range(1, n)))

if __name__ == '__main__':
    main()
