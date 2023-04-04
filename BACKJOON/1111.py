line = []
answer: int = 0

for _ in range(8):
    line.append(input())

for i in range(8):
    for j in range(8):
        if i % 2 == 0 and j % 2 == 0 and line[i][j] == 'F':
            answer += 1
        if i % 2 == 1 and j % 2 == 1 and line[i][j] == 'F':
            answer += 1

print(answer)