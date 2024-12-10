import sys


input = sys.stdin.readline

def Map_array(check):
    rtr = 0
    for idx, i in enumerate(check):
        rtr += (2**idx)*i
    return rtr

def direct_dp(idx, lst, dp, check, count, a):
    if count == len(lst):
        return lst[idx][i]
    else:
        if check in dp[idx]:
            return dp[idx][check]
        dp[idx][check] = 10000000000
        for i in range(len(lst)):
            if 1 << i & check:
                continue
            dp[idx][check] = min(dp[idx][check], lst[idx][i]+direct_dp(i, lst, dp, check + (1<<i), count+1, a))
        return dp[idx][check]
            

T = int(input())
answer = []
for _ in range(T):
    N = int(input())
    lst = []
    check = [1 for _ in range(N)]
    for i in range(N):
        tempt_list = list(map(float, input().split()))
        lst.append(tempt_list)
    dp = []
    for _ in range(N):
        dp.append(dict())
    ans = 1000000000000000
    for i in range(N):
        check = 1 << i
        ans = min(ans, direct_dp(i,lst,dp,check, 1, i))
    answer.append(ans)
for k in answer:
    print(k)