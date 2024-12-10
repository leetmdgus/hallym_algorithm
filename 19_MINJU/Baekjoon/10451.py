import sys
from collections import deque

input = sys.stdin.readline

T = int(input())

answer = []
for _ in range(T):
    N = int(input())
    lst = list(map(int, input().split()))
    lst.insert(0,0)
    q = deque([])
    check = [0 for _ in range(N+1)]
    ans = 0
    for i in range(1, N+1):
        if check[i] == 0:
            q.append(i)
            while len(q) > 0:
                tmp = q.popleft()
                if check[lst[tmp]] == 0:
                    check[lst[tmp]] = 1
                    q.append(lst[tmp])
            ans += 1
    answer.append(ans)
for i in answer:
    print(i)