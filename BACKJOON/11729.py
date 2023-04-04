plate = int(input())
count = 0
move_Data = []


def hanoi(n, start, target, temp):
    global count
    count += 1
    if n == 1:
        move_Data.append(start+" "+target)
    else:
        hanoi(n - 1, start, temp, target)
        move_Data.append(start+" "+target)
        hanoi(n - 1, temp, target, start)


hanoi(plate, '1', '3', '2')
print(count)
for index in move_Data:
    print(index)