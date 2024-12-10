import sys
from collections import deque


input = sys.stdin.readline

N, M, X, Y = map(int, input().split())
A_list = list(map(int, input().split()))
A_list.insert(0,0)
lst = []
for i in range(N+1):
    lst.append([])
for i in range(M):
    v, u = map(int, input().split())
    lst[v].append(u)
    lst[u].append(v)
B_list = list(map(int, input().split()))
q = deque([])
check = [0 for _ in range(N+1)]
money = [0 for _ in range(N+1)]
for i in B_list:
    q.append(i)
    check[i] = 1
    
while len(q) > 0:
    length = len(q)
    for _ in range(length):
        tmp = q.popleft()
        for t in lst[tmp]:
            if check[t] == 0:
                check[t] = check[tmp] + 1
                q.append(t) 
for i in range(1,N+1):
    if check[i] != 0 : money[i] = A_list[i] * (check[i]-1)
ch = 0
cnt = 0
for i in range(1,N+1):
    if check[i] == 0:
        ch += 1
        if A_list[i] == 0:
            cnt += 1
if ch != 0 and ch != cnt:
    print(-1)
else:
    visited = set()
    ans = 0
    answer = []
    for i in range(1,N+1):
        if check[i] != 0:
            answer.append(money[i])
    money.sort()
    for i in range(X):
        ans += money[len(money)-1-i]
    # print(money)/
    print(ans)
        
        