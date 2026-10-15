# 3-串珠吊飾 | 2025/11/10~2025/11/14 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/BeadedCharm.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m, q = next(it), next(it), next(it)
    graph = [[] for _ in range(n)]
    for edge in range(m):
        a, b = next(it), next(it)
        graph[a].append((b, edge))
        graph[b].append((a, edge))
    tin, low, size = [-1] * n, [0] * n, [1] * n
    parent, parent_edge = [-1] * n, [-1] * n
    tin[0] = low[0] = 0
    clock, lost = 1, {}
    stack = [(0, iter(graph[0]))]
    while stack:
        u, children = stack[-1]
        try:
            v, edge = next(children)
        except StopIteration:
            stack.pop()
            p = parent[u]
            if p >= 0:
                size[p] += size[u]
                low[p] = min(low[p], low[u])
                if low[u] > tin[p]:
                    lost[min(u, p), max(u, p)] = size[u]
            continue
        if edge == parent_edge[u]:
            continue
        if tin[v] >= 0:
            low[u] = min(low[u], tin[v])
        else:
            parent[v], parent_edge[v] = u, edge
            tin[v] = low[v] = clock
            clock += 1
            stack.append((v, iter(graph[v])))
    answer = []
    for _ in range(q):
        a, b = next(it), next(it)
        answer.append(str(n - lost.get((min(a, b), max(a, b)), 0)))
    print('\n'.join(answer))

if __name__ == '__main__':
    main()
