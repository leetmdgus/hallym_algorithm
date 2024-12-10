import sys
from collections import deque

input = sys.stdin.readline

R,C = map(int, input().split())
lst = []
check = []
INF = 10000000000000
for i in range(R):
    check_list = [INF for _ in range(C)]
    check.append(check_list)
for i in range(R):
    tempt = input().strip()
    tempt_list = [k for k in tempt]
    lst.append(tempt_list)
J_x = 0
J_y = 0
fire_q = deque([])
for i in range(R):
    for j in range(C):
        if lst[i][j] == 'J':
            J_x = i
            J_y = j
        elif lst[i][j] == 'F':
            fire_q.append((i,j))
J_q = deque([(J_x, J_y)])
ck = [1,0,-1,0]
cj = [0,1,0,-1]
check[J_x][J_y] = 1
while len(J_q) > 0:
    length = len(fire_q)
    for i in range(length):
        x,y = fire_q.popleft()
        for k in range(4):
            nx = x + ck[k]
            ny = y + cj[k]
            if nx >= 0 and nx < R and ny >= 0 and ny < C and lst[nx][ny] != '#' and lst[nx][ny] != 'F':
                lst[nx][ny] = 'F'
                fire_q.append((nx,ny))
    length = len(J_q)
    for i in range(length):
        x,y = J_q.popleft()
        for k in range(4):
            nx = x + ck[k]
            ny = y + cj[k]
            if nx >= 0 and nx < R and ny >= 0 and ny < C and lst[nx][ny] == '.' and check[nx][ny] == INF:
                check[nx][ny] = check[x][y]+1
                J_q.append((nx,ny))
ans = INF
for i in range(R):
    ans = min(check[i][0], check[i][C-1], ans)
for i in range(C):
    ans = min(check[0][i], check[R-1][i], ans)
if ans == INF:
    print("IMPOSSIBLE")
else:
    print(ans)
