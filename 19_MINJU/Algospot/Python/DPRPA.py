import sys
import copy
def dfs(idx, lst, d, count, ans, N):
    global answer
    if idx == len(lst) or count == N:
        return count
    else:
        rtr = count
        for i in range(idx+1, len(lst)):
            if lst[i] - lst[idx] >= d:
                tempt = dfs(i, lst, d, count+1, ans, N)
                if tempt >= N:
                    rtr = max(tempt, rtr)
                    # print(idx, count)
                    answer = min(answer, lst[i] - lst[idx])
        return rtr
        


input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    lst = list(map(float, input().split()))
    for i in range(len(lst)):
        lst[i] = lst[i]*1000
    start = 0
    end = 2400003322
    d = 0
    while(start <= end):
        mid = (start + end) // 2
        pre_val = lst[0]
        count = 1
        for i, val in enumerate(lst):
            if i == 0:
                continue
            if pre_val + mid <= val:
                pre_val = val
                count += 1
        if count >= N:
            d = mid
            start = mid +1
        else:
            end = mid-1
    print("{:.2f}".format(d/1000))
    # print(round(d/1000,2))
    