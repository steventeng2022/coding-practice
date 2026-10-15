# 1-棟距 | 2025/12/22~2025/12/26 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Spacing.pdf
import sys

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    n, m = next(it), next(it)
    heights = [next(it) for _ in range(n)]
    distance = [n] * n
    stack = []
    for i, h in enumerate(heights):
        while stack and heights[stack[-1]] < h:
            stack.pop()
        if stack:
            distance[i] = i - stack[-1]
        stack.append(i)
    stack.clear()
    for i in range(n - 1, -1, -1):
        while stack and heights[stack[-1]] < heights[i]:
            stack.pop()
        if stack:
            distance[i] = min(distance[i], stack[-1] - i)
        stack.append(i)
    print(*(distance[next(it)] for _ in range(m)))

if __name__ == '__main__':
    main()
