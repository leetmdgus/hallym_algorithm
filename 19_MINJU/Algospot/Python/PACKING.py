import sys
import copy
input = sys.stdin.readline


def PACKING(n,m,lst,dp, ans):
    if m < 0:
        return -100000000
    elif n == len(lst):
        return 0
    
    if dp[n][m] != -1:
        return dp[n][m]
    self_include = PACKING(n+1,m-lst[n][1], lst, dp, ans) + lst[n][2]
    
    self_exclude = PACKING(n+1,m,lst,dp, ans)
    if self_exclude > self_include:
        dp[n][m] = self_exclude
        ans[n][m] = -1
        return dp[n][m]
    else:
        dp[n][m] = self_include
        ans[n][m] = 1
        return dp[n][m]



T = int(input())
answer = []
answer_lst = []
for _ in range(T):
    N, W = map(int, input().split())
    lst = []
    dp = []
    dp_lst = []
    for _ in range(N+1):
        tempt_list = [-1 for _ in range(W+1)]
        dp.append(tempt_list)
        dp_lst.append([0 for _ in range(W+1)])
    for _ in range(N):
        tempt = list(input().split())
        name, volume, priority = tempt[0], int(tempt[1]), int(tempt[2])
        lst.append((name, volume, priority))
    ans = [0 for _ in range(N)]
    a = PACKING(0,W, lst, dp, dp_lst)
    t = W
    l = []
    for i in range(N):
        if dp_lst[i][t] == 1:
            l.append(i)
            t -= lst[i][1]
    print(a, len(l))
    for k in dp:
        print(k)
    for k in l:
        print(lst[k][0])
            
        

        
    
            
    