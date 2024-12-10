import sys
import heapq
input = sys.stdin.readline
T = int(input())
INF = 1000000000000000000000
for _ in range(T):
    N, M = map(int, input().split())
    lst = []
    for _ in range(N):
        tempt_list = []
        lst.append(tempt_list)
    for _ in range(M):
        x, y, w = map(float, input().split())
        x = int(x)
        y = int(y)
        lst[x].append((w,y))
        lst[y].append((w,x))
    check = [0 for _ in range(N)]
    heap = []
    heapq.heappush(heap, (1,0)) # (weight, vertex)
    weight_list = [INF for _ in range(N)]
    while True:
        w, v = heapq.heappop(heap)
        if check[v] == 1: continue
        check[v] = 1
        weight_list[v] = w
        if v == N-1:
            break
        for weight, vertex in lst[v]:
            heapq.heappush(heap, (weight_list[v]*weight, vertex))
    print(round(weight_list[N-1], 10))
        
        
            