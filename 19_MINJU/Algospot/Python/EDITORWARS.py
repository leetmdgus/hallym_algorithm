import sys

input = sys.stdin.readline

def swap(a, b, lst):
    tmp = lst[a]
    lst[a] = lst[b]
    lst[b] = tmp

def find(idx, lst):
    if idx == lst[idx]:
        return idx
    else:
        lst[idx] = find(lst[lst[idx]])
        return lst[idx]

def union(a,b,lst,rank):
    a = find(a)
    b = find(b)
    
    if a == b:
        return
    if rank[a] > rank[b]:
        swap(a,b,lst)
    lst[a] = b
    if rank[a] == rank[b]:
        rank[b] += 1
        
        

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    