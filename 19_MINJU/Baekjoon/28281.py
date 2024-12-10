import sys

input = sys.stdin.readline

N, X = map(int, input().split())
lst = list(map(int, input().split()))
max_ = 1000000000000
for i in range(N-1):
    max_ = min(lst[i]*X+lst[i+1]*X, max_)
print(max_)