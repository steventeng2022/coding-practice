# 1-檢查答案 | 2026/05/04~2026/05/08 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Dependency.pdf
import sys
from collections import deque

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    graph = [[] for _ in range(n)]
    degree = [0] * n
    for _ in range(m):
        u, v = next(it) - 1, next(it) - 1
        graph[u].append(v)
        degree[v] += 1
    queue = deque(i for i in range(n) if degree[i] == 0)
    unique, processed = True, 0
    while queue:
        if len(queue) != 1:
            unique = False
        u = queue.popleft()
        processed += 1
        for v in graph[u]:
            degree[v] -= 1
            if degree[v] == 0:
                queue.append(v)
    print(0 if unique and processed == n else 1)

if __name__ == '__main__':
    main()
