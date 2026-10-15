# 3-BABA | 2026/06/8~2026/06/12 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/BABA.pdf
import sys

def main():
    a, b, c, k = map(int, sys.stdin.buffer.read().split())
    count = [a, b, c]
    total = sum(count)
    if max(count) > k * (total - max(count) + 1):
        print('No Solution')
        return
    answer, previous, run = [], -1, 0
    while total:
        for d in (2, 1, 0):
            if not count[d] or (previous == d and run == k):
                continue
            count[d] -= 1
            remaining = total - 1
            # 當前尾端還能接 k-new_run 個同字元；其餘字元可接完整區塊。
            new_run = run + 1 if previous == d else 1
            feasible = True
            for x in range(3):
                capacity = k * (remaining - count[x] + 1)
                if x == d:
                    capacity -= new_run
                if count[x] > capacity:
                    feasible = False
                    break
            if feasible:
                answer.append(chr(65 + d))
                previous, run = d, new_run
                total -= 1
                break
            count[d] += 1
        else:
            raise AssertionError('feasibility invariant failed')
    print(''.join(answer))

if __name__ == '__main__':
    main()
