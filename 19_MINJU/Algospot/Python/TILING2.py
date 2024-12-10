import sys

def direct_dfs(idx, dp):
    if idx == 1:
        return 1
    elif idx == 2:
        return 2
    if dp[idx] != -1:
        return dp[idx]
    dp[idx] = (direct_dfs(idx-1, dp) + direct_dfs(idx-2, dp))%1000000007
    return dp[idx]

input = sys.stdin.readline

T = int(input())

answer = []
for _ in range(T):
    a = int(input())
    dp = []
    for _ in range(101):
        dp.append(-1)
    dp[1] = 1
    dp[2] = 2
    direct_dfs(a, dp)
    answer.append(dp[a])
for k in answer:
    print(k)
    