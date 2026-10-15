# 3-平均值 | 2026/05/04~2026/05/08 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/BeatAverage.pdf
import sys
from bisect import bisect_left, bisect_right, insort
from math import isqrt

class Blocks:
    def __init__(self, values, width):
        self.a, self.width = values, width
        self.blocks = [sorted(values[i:i + width]) for i in range(0, len(values), width)]
        self.sums = [sum(b) for b in self.blocks]

    def modify(self, index, delta):
        b = index // self.width
        block = self.blocks[b]
        block.pop(bisect_left(block, self.a[index]))
        self.a[index] += delta
        insort(block, self.a[index])
        self.sums[b] += delta

    def query(self, left, right):
        width, a = self.width, self.a
        lb, rb = left // width, (right - 1) // width
        if lb == rb:
            total = sum(a[left:right])
            length = right - left
            return sum(x * length > total for x in a[left:right])
        edge_left, edge_right = (lb + 1) * width, rb * width
        total = sum(a[left:edge_left]) + sum(a[edge_right:right]) + sum(self.sums[lb + 1:rb])
        length = right - left
        threshold = total // length
        result = sum(x > threshold for x in a[left:edge_left])
        result += sum(x > threshold for x in a[edge_right:right])
        for b in range(lb + 1, rb):
            block = self.blocks[b]
            result += len(block) - bisect_right(block, threshold)
        return result

def main():
    it = iter(sys.stdin.buffer.read().split())
    n, q = int(next(it)), int(next(it))
    values = [int(next(it)) for _ in range(n)]
    width = max(1, isqrt(n))
    columns = {b'A': Blocks(values, width), b'B': Blocks([500 - x for x in values], width)}
    answer = []
    for _ in range(q):
        op, x, y = int(next(it)), int(next(it)), int(next(it))
        column = columns[next(it)]
        if op == 1:
            column.modify(x - 1, y)
        else:
            answer.append(str(column.query(x - 1, y)))
    print('\n'.join(answer))

if __name__ == '__main__':
    main()
