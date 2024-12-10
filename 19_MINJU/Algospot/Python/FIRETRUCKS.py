import sys
import heapq



input = sys.stdin.readline
T = int(input())
INF = 1000000000000000
answer = []

for _ in range(T):
    V, E, m, n = map(int, input().split())
    lst = []
    for _ in range(V+1):
        lst.append([])
    for _ in range(E):
        v, e, w = map(int, input().split())
        lst[v].append((e,w))
        lst[e].append((v,w))
    heap = []
    check = [0 for _ in range(V+1)]
    weight_list = [INF for _ in range(V+1)]
    fire_list = list(map(int, input().split()))
    fireTruck_list = list(map(int, input().split()))
    for k in fireTruck_list:
        weight_list[k] = 0
        heapq.heappush(heap, (0, k))
    while len(heap) > 0:
        w, v = heapq.heappop(heap)
        if check[v] == 1:
            continue
        check[v] = 1
        for t in lst[v]:
            a,b = t
            if weight_list[a] > b + weight_list[v]:
                weight_list[a] = b + weight_list[v]
                heapq.heappush(heap, (weight_list[a], a))
    hap = 0
    for k in fire_list:
        hap += weight_list[k]
    answer.append(hap)
for k in answer:
    print(k)

