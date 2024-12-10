import sys

input = sys.stdin.readline

X, K = map(int, input().split())
left_shoes = [0 for _ in range(K+1)]
right_shoes = [0 for _ in range(K+1)]
left_color = 0
right_color = 0
lst = list(map(int, input().split()))
for i in range(len(lst)//2):
    left_shoes[lst[i]] += 1
for i in range(len(lst)//2, len(lst),1):
    right_shoes[lst[i]] += 1
answer = 0
for i in range(1,K+1):
    answer += (left_shoes[i]*(X-right_shoes[i]))
print(answer)
