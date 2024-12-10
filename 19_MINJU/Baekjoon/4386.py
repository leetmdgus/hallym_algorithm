import sys
import heapq
input = sys.stdin.readline

n = int(input())

lst = []
for _ in range(n):
    a, b = map(float, input().split())
    lst.append((a,b))
vertex_list = []
for _ in range(n):
    vertex_list.append([0 for _ in range(n)])
for i in range(n):
    for j in range(i,n):
        length = ((lst[i][0]-lst[j][0])**2 + (lst[i][1]-lst[j][1])**2)**(1/2)
        vertex_list[i][j] = length
        vertex_list[j][i] = length
check = [0 for _ in range(n)]
heap = []
heapq.heappush(heap, (0,0))
count = 0
ans = 0
while True:
    a, b = heapq.heappop(heap)
    if check[b] == 1:
        continue
    check[b] = 1
    count += 1
    ans += a
    if count == n:
        break
    for idx, length in enumerate(vertex_list[b]):
        if check[idx] == 0:
            heapq.heappush(heap, (length, idx))
print(round(ans,2))
