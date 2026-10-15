# 3-調香師 | 2026/06/8~2026/06/12 | 新手組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Perfumer.pdf
import sys

def main():
    it = iter(sys.stdin.buffer.read().split())
    n = int(next(it))
    names, owner = [], {}
    for i in range(n):
        names.append(next(it))
        count = int(next(it))
        for _ in range(count):
            owner[next(it)] = i
    total = [0] * n
    for _ in range(int(next(it))):
        oil, amount = next(it), int(next(it))
        total[owner[oil]] += amount
    print(names[max(range(n), key=total.__getitem__)].decode())

if __name__ == '__main__':
    main()
