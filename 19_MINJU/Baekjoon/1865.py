import sys
from collections import deque
input = sys.stdin.readline
        


answer = []
INF = 10000000000000
T = int(input())
for _ in range(T):
    N, M, W = map(int, input().split())
    check_lst = []
    lst = []
    W_lst = []
    for _ in range(N+1):
        check_lst.append([INF for _ in range(N+1)])
        lst.append([])
        W_lst.append([])
    for _ in range(M):
        u, v, w = map(int, input().split())
        if w < check_lst[u][v]:
            lst[u].append((v,w))
            lst[v].append((u,w))
    for _ in range(W):
        u, v, w = map(int, input().split())
        lst[u].append((v,-1*w))
    check = [INF for _ in range(N+1)]
    q = deque([])
    visited = set()
    for i in range(1,N+1):
        if i not in visited:
            visited.add(i)
            check[i] = 1
            q.append(i)
            while len(q) > 0:
                tmp = q.popleft()
                for k in lst[tmp]:
                    v, w= k
                    if v not in visited:
                        visited.add(v)
                        q.append(v)
    check[1] = 1
    for i in range(N):
        for j in range(1,N+1):
            for k in lst[j]:
                v,w = k
                if check[j] != INF and check[v] > check[j] + w:
                    check[v] = check[j] + w 
    flag = False
    for i in range(1,N+1):
        for k in lst[i]:
            v, w = k
            if check[i] != INF and check[v] > check[i] + w:
                flag = True
    if flag: answer.append("YES")
    else : answer.append("NO")
                
for k in answer:
    print(k)

        
    
        