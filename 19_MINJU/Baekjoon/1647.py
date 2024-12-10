import sys
import heapq

def find(idx, lst):
    if idx == lst[idx]:
        return idx
    else:
        lst[idx] = find(lst[idx], lst)
        return lst[idx]
def union(a, b, lst):
    a = find(a, lst)
    b = find(b, lst)
    if a != b:
        lst[a] = b



input = sys.stdin.readline


N, M = map(int, input().split())
heap = []
lst = [i for i in range(N+1)]
for i in range(M):
    u, v, w = map(int, input().split())
    heapq.heappush(heap,(w,u,v))


ans = 0
count = 0
while len(heap) > 0:
    if count == N-2:
        break
    w, u, v = heapq.heappop(heap)
    if find(u, lst) == find(v, lst):
        continue
    else:
        count += 1
        union(u,v, lst)
        ans += w

print(ans)
        



