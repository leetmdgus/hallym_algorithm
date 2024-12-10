import sys

input = sys.stdin.readline

def direct_dfs(a, b, dp):
    if a == 1 and b == 1:
        return 1
    elif b == 1:
        return a
    if dp[a][b] != -1:
        return dp[a][b]
    else:
        rtr = a+b-1
        for i in range(1,b):
            rtr += (direct_dfs(i, b-i, dp) * (a+i-1))%10000000
        dp[a][b] = rtr
        return dp[a][b]
            
    

T = int(input())
answer =[]
dp = []
for _ in range(101):
    tempt_lst = [-1 for _ in range(101)]
    dp.append(tempt_lst)
for _ in range(T):
    n = int(input())
    ans = 1
    for i in range(1, n):
        ans =(ans + direct_dfs(i, n-i, dp))%10000000
    answer.append(ans)
for k in answer:
    print(k)
# for i in range(10):
#     for j in range(10):
#         print(dp[i][j], end= ' ')
#     print()
    