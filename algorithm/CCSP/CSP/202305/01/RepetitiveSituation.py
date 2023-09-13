n = int(input())
chess = {}
for i in range(n):
    temp = ''
    for j in range(8):
        temp += input()
    if temp not in chess:
        chess[temp] = 1
    else:
        chess[temp] += 1
    print(chess[temp])