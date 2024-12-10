import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline


T= int(input())

def direct_dfs(dp, n, m):
    if n <= 0:
        return 1
    if m == 0:
        return 0
    if dp[n][m] != -1:
        return dp[n][m]
    dp[n][m] = direct_dfs(dp, n-2, m-1) * (3/4) + direct_dfs(dp, n-1, m-1) * (1/4)
    return dp[n][m]


answer = []
dp = []
for i in range(1001):
    tempt_lst = []
    for j in range(1001):
        tempt_lst.append(-1)
    dp.append(tempt_lst)
for _ in range(T):
    n, m = map(int, input().split())
    if dp[n][m] == -1:
        direct_dfs(dp, n, m)    
    answer.append(round(dp[n][m], 10))
for k in answer:
    print(k)