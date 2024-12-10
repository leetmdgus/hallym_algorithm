import sys
from collections import deque
                
    

input = sys.stdin.readline

n, m = map(int, input().split())
lst = []
for i in range(n):
    tempt_list = list(map(int, input().split()))
    lst.append(tempt_list)
x = 0
y = 0
for i in range(n):
    for j in range(m):
        if lst[i][j] == 2:
            x = i
            y = j
            break
    if x == i and y == j:
        break
ck = [1,0,-1,0]
cj = [0,1,0,-1]
dp = []
for i in range(n):
    tempt_list = [0 for _ in range(m)]
    dp.append(tempt_list)
q = deque([])
q.append((x,y))
count = 1
while len(q) > 0:
    length = len(q)
    for i in range(length):
        x, y = q.popleft()
        for k in range(4):
            nx = x + ck[k]
            ny = y + cj[k]
            if nx >= 0 and nx < n and ny >= 0 and ny < m and lst[nx][ny] == 1 and dp[nx][ny] == 0:
                dp[nx][ny] = count
                q.append((nx,ny))
    count += 1
for i in range(n):
    for j in range(m):
        if lst[i][j] == 1 and dp[i][j] == 0:
            print(-1, end= ' ')
        else:
            print(dp[i][j], end =' ')
    print()
        