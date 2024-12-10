import sys
import heapq
def find(x, lst):
    if x == lst[x]:
        return x
    else:
        lst[x] = find(lst[x], lst)
        return lst[x]
def union(a,b,lst):
    a = find(a, lst)
    b = find(b, lst)
    if a != b:
        lst[a] = b
input = sys.stdin.readline

INF = 100000000000000
N = int(input())
lst = []
for i in range(N):
    X,Y,Z = map(int, input().split())
    lst.append((X,Y,Z,i))
heap = []
lst.sort(key = lambda x : x[0])
for i in range(len(lst)-1):
    heapq.heappush(heap, (abs(lst[i][0]-lst[i+1][0]), lst[i][3], lst[i+1][3]))
lst.sort(key = lambda x : x[1])
for i in range(len(lst)-1):
    heapq.heappush(heap, (abs(lst[i][1]-lst[i+1][1]), lst[i][3], lst[i+1][3]))
lst.sort(key = lambda x : x[2])
for i in range(len(lst)-1):
    heapq.heappush(heap, (abs(lst[i][2]-lst[i+1][2]), lst[i][3], lst[i+1][3]))
count = 0
ans = 0
check = [i for i in range(N)]
while len(heap) > 0:
    w,u,v = heapq.heappop(heap)
    if find(u, check) == find(v, check):
        continue
    else:
        union(u,v,check)
        count += 1
        ans += w
        if count == N-1:
            break
print(ans)    