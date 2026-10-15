# 2-紙膠帶 | 2026/03/16~2026/03/20 | 潛力組
# 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tape.pdf
import sys

def main():
    data = sys.stdin.buffer.read().split()
    limits = list(map(int, data[1:27]))
    tape = [x - 97 for x in data[27]]
    answer = 0
    for scoring in set(tape):
        frequency = [0] * 26
        left = kinds = 0
        for char in tape:
            if frequency[char] == 0:
                kinds += 1
            frequency[char] += 1
            while kinds > 3 or (char != scoring and frequency[char] > limits[char]):
                old = tape[left]
                frequency[old] -= 1
                if frequency[old] == 0:
                    kinds -= 1
                left += 1
            if kinds == 3 and frequency[scoring] > answer:
                answer = frequency[scoring]
    print(answer)

if __name__ == '__main__':
    main()
