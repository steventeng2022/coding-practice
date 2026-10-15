# 3-迷宮逃離 | 2020/04/27~2020/05/04 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A3-Escape.pdf
import sys

def main():
    it = iter(sys.stdin.buffer.read().split())
    n, t = int(next(it)), int(next(it))
    parent = list(range(n))
    size, parity = [1] * n, [0] * n
    def find(x):
        if parent[x] != x:
            p = parent[x]
            parent[x] = find(p)
            parity[x] ^= parity[p]
        return parent[x]
    possible = True
    for _ in range(t):
        a, b, relation = next(it), next(it), next(it)
        u, v = int(a[:-1]) - 1, int(b[:-1]) - 1
        # x[u] 表示左雕像狀態；右雕像是 x[u] xor 1。
        expected = (relation == b'D') ^ (a[-1] == 82) ^ (b[-1] == 82)
        ru, rv = find(u), find(v)
        difference = parity[u] ^ parity[v] ^ expected
        if ru == rv:
            if difference:
                possible = False
        else:
            if size[ru] < size[rv]:
                ru, rv = rv, ru
            parent[rv] = ru
            parity[rv] = difference
            size[ru] += size[rv]
    print('Easy Peasy' if possible else 'Impossible')

if __name__ == '__main__':
    main()
