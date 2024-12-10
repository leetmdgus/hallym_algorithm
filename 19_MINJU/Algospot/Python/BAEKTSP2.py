import sys


input = sys.stdin.readline

def Map_array(check):
    rtr = 0
    for idx, i in enumerate(check):
        rtr += (2**idx)*i
    return rtr

def direct_dp(idx, lst, dp, check, count, a):
    if count == len(lst):
        return lst[idx][a]
    else:
        if check in dp[idx]:
            return dp[idx][check]
        dp[idx][check] = 10000000000
        for i in range(len(lst)):
            if 1 << i & check:
                continue
            dp[idx][check] = min(dp[idx][check], lst[idx][i]+direct_dp(i, lst, dp, check + (1<<i), count+1, a))
        return dp[idx][check]
            


N = int(input())
lst = []
check = [1 for _ in range(N)]
eulid_lst = []
for i in range(N):
    tempt_list = list(map(float, input().split()))
    eulid_lst.append(tempt_list)
for i in range(N):
    a,b = eulid_lst[i]
    tempt_list = []
    for j in range(N):
        t_a, t_b = eulid_lst[j]
        tempt_list.append(((a-t_a)**2+(b-t_b)**2)**(1/2))
    lst.append(tempt_list)
dp = []
for _ in range(N):
    dp.append(dict())
ans = 1000000000000000
for i in range(1):
    check = 1 << i
    tmp = direct_dp(i,lst,dp,check, 1, i)
    ans = min(ans, tmp)
print(ans)