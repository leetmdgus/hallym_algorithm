import sys
from collections import deque


input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    lst = []
    for _ in range(N):
        x, y = map(float, input().split())
        lst.append((x,y))
    lst_d = []
    for _ in range(N):
        lst_d.append([0]*N)
    for i in range(N):
        for j in range(N):
            lst_d[i][j] = ((lst[i][0]-lst[j][0])**2 + (lst[i][1]-lst[j][1])**2)**(1/2)
    q = deque([])
    start = 0.0
    end = 1000000.0
    d = 0
    cnt =0 
    while end-start >= 0.00000001:
        cnt += 1
        mid = (start + end)/2
        q.append(0)
        check = [0]*N
        check[0] = 1
        count = 1
        while len(q) > 0:
            x = q.popleft()
            for i in range(len(lst)):
                if check[i] == 0 and lst_d[x][i] <= mid:
                    check[i] = 1
                    q.append(i)
                    count += 1
        if count == len(check):
            end = mid
            d = mid
        else:
            start = mid
    print("{:.2f}".format(d))
    print(cnt)
            
        
                    
    
    