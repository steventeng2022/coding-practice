# 2-作物種植 | 2026/06/8~2026/06/12 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Plant2.pdf
import sys

def prefix_rectangles(rows):
    width = len(rows[0])
    heights = [0] * (width + 1)
    result, best = [], 0
    for row in rows:
        for j, value in enumerate(row):
            heights[j] = heights[j] + 1 if value else 0
        stack = [-1]
        for j in range(width + 1):
            while stack[-1] != -1 and heights[stack[-1]] > heights[j]:
                h = heights[stack.pop()]
                best = max(best, h * (j - stack[-1] - 1))
            stack.append(j)
        result.append(best)
    return result

def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    h, w, k = next(it), next(it), next(it)
    grid = [list(next(it) for _ in range(w)) for _ in range(h)]
    top = prefix_rectangles(grid)
    answer = top[-1]
    if k == 2:
        bottom = prefix_rectangles(grid[::-1])
        for i in range(h - 1):
            answer = max(answer, top[i] + bottom[h - i - 2])
        columns = list(zip(*grid))
        left = prefix_rectangles(columns)
        right = prefix_rectangles(columns[::-1])
        for j in range(w - 1):
            answer = max(answer, left[j] + right[w - j - 2])
    print(answer)

if __name__ == '__main__':
    main()
