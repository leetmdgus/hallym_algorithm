import sys
from collections import deque
import heapq
input = sys.stdin.readline


N, M = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort()
used_list = []
for i in range(M):
    used_list.append(list(map(int, input().split())))
used_list.sort()
heap = []
min_hap_list = [0,lst[0]]
max_hap_list = [0,lst[len(lst)-1]]
for i in range(1,len(lst)):
    min_hap_list.append(min_hap_list[-1]+lst[i])
for i in range(len(lst)-2,-1,-1):
    max_hap_list.append(max_hap_list[-1]+lst[i])
heapq.heappush(heap, used_list[0][1])
max_ = 0
min_ = 0
start = used_list[0][0]
# print(min_hap_list)
# print(max_hap_list)
for t in range(1, len(used_list)):
    a,b = used_list[t]
    
    if heap[0] < a:
        while len(heap) > 0 and heap[0] < a:
            length = (heap[0]-start+1)
            max_ += (max_hap_list[len(heap)] * length) 
            min_ += (min_hap_list[len(heap)] * length)
            start = heap[0]+1
            heapq.heappop(heap)
        length = (a-start)
        max_ += (max_hap_list[len(heap)] * length)
        min_ += (min_hap_list[len(heap)] * length) 
        start = a
    else:
        length = (a-start)
        max_ += (max_hap_list[len(heap)] * length)
        min_ += (min_hap_list[len(heap)] * length) 
        start = a
    heapq.heappush(heap, b)
while len(heap) > 0:
    length = (heap[0]-start+1)
    max_ += (max_hap_list[len(heap)] * length) 
    min_ += (min_hap_list[len(heap)] * length)
    start = heap[0]+1
    heapq.heappop(heap)
print(min_, max_)
    