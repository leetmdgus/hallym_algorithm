import sys
sys.setrecursionlimit(10**8)

count = 2
def dfs(idx, lst, check):
    global count
    for i in lst[idx]:
        if check[i] == 0:
            check[i] = count
            count += 1
            dfs(i,lst,check)
    


input = sys.stdin.readline

N,M,R = map(int, input().split())
lst = []
for i in range(N+1):
    lst.append([])
for i in range(M):
    a, b = map(int, input().split())
    lst[a].append(b)
    lst[b].append(a)
for i in range(1, N+1):
    lst[i].sort()
check = [0 for _ in range(N+1)]
check[R] = 1
dfs(R,lst,check)
for i in range(1,N+1):
    print(check[i])