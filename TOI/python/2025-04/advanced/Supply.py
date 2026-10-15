# 3-供給調度 | 2025/04/28~2025/05/02 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Supply.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m, q = next(it), next(it), next(it)
    edges = [(next(it), next(it), next(it)) for _ in range(m)]
    queries = [(next(it), next(it), next(it)) for _ in range(q)]
    target = next(it)
    def exceeds(t):
        extra = {}
        for u, v, value in queries[:t]:
            extra[u, v] = extra.get((u, v), 0) + value
        weighted = sorted((w + extra.get((u, v), 0), u, v) for u, v, w in edges)
        parent = list(range(n))
        size = [1] * n
        def find(u):
            while parent[u] != u:
                parent[u] = parent[parent[u]]
                u = parent[u]
            return u
        total, used = 0, 0
        for w, u, v in weighted:
            u, v = find(u), find(v)
            if u == v:
                continue
            if size[u] < size[v]:
                u, v = v, u
            parent[v] = u
            size[u] += size[v]
            total += w
            used += 1
            if total > target:
                return True
            if used == n - 1:
                break
        return total > target
    if not exceeds(q):
        print(-1)
        return
    left, right = 0, q
    while left < right:
        mid = (left + right) // 2
        if exceeds(mid):
            right = mid
        else:
            left = mid + 1
    print(left)

if __name__ == '__main__':
    main()
