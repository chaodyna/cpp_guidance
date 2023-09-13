n, d = map(int, input().split())
Q = [[i for i in map(int, input().split())] for j in range(n)]
K = [[i for i in map(int, input().split())] for j in range(n)]
V = [[i for i in map(int, input().split())] for j in range(n)]
W = [i for i in map(int, input().split())]
tmp = []
ans = []

# 计算 K的转置 * V = tmp
for i in range(d):
    tmp.append([])
    for j in range(d):
        tmp[i].append(0)
        for k in range(n):
            tmp[i][j] += K[k][i]*V[k][j]

# 计算 Q * tmp = ans
for i in range(n):
    ans.append([])
    for j in range(d):
        ans[i].append(0)
        for k in range(d):
            ans[i][j] += Q[i][k]*tmp[k][j]
        ans[i][j] *= W[i]

for i in range(n):
    a = []
    for j in range(d):
        a.append(ans[i][j])
    print(*a)