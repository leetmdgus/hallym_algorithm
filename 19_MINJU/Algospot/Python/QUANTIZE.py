import sys
import math
input = sys.stdin.readline

def direct_dfs(index, hap_lst, lst, N, S, part, squared_hap, dp):
    if index == N+1 and part == 0:
        return 0
    if part == 0:
        return 10000000000000
    if dp[index][part] != -1:
        return dp[index][part]
    rtr = 1000000000000
    for i in range(index,N+1):
        tempt = round((hap_lst[i]-hap_lst[index-1])/(i-index+1))
        if tempt >= 1 and tempt <= 1000:
            hap = (squared_hap[i]-squared_hap[index-1]) - ((2*tempt) * (hap_lst[i]-hap_lst[index-1])) + ((tempt**2)*(i-index+1))
            rtr = min(rtr, hap +direct_dfs(i+1, hap_lst, lst, N, S, part-1, squared_hap, dp))
    dp[index][part] = rtr
    return rtr

T = int(input())
answer = []
for _ in range(T):
    N, S = map(int, input().split())
    lst = list(map(int, input().split()))
    lst.sort()
    hap_lst = [0]  
    squared_hap = [0]
    dp = []
    for i in range(N+2):
        tempt_lst = []
        for j in range(S+1):
            tempt_lst.append(-1)
        dp.append(tempt_lst)
    for i in range(N):
        hap_lst.append(hap_lst[i]+lst[i])
        squared_hap.append(squared_hap[i]+lst[i]**2)
    ans = direct_dfs(1, hap_lst, lst, N, S, S, squared_hap, dp)
    answer.append(ans)
for k in answer:
    print(k)