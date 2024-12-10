import sys

input = sys.stdin.readline

T = int(input())
dp = [0,1,2]
for i in range(3,100):
    tempt = (dp[i-1]+dp[i-2])%1000000007
    dp.append(tempt)
answer = []
for _ in range(T):
    n = int(input()) 
    ans = 0
    if n%2 == 1:
        a,b = (n-2)//2, (n-2)//2+1
        ans = dp[a]*dp[b]*2
        tmp = (n-1)//2
        ans += (dp[tmp]*(dp[tmp]-1))
    else:
        a = (n)//2
        ans = dp[a]*(dp[a]-1)
        tmp = (n-2)//2
        ans += (dp[tmp] * (dp[tmp]-1))
    answer.append(ans%1000000007)
for k in answer:
    print(k)