import sys

def LIS(idx, lst, dp):
    if dp[idx] != 0:
        return dp[idx]
    rtr = 1
    for i in range(idx, len(lst)):
        if lst[i] > lst[idx]:
            rtr = max(rtr, 1+LIS(i, lst, dp))
    dp[idx] = rtr
    return rtr
    

input = sys.stdin.readline

T = int(input())
answer = []

for _ in range(T):
    N = int(input())
    theme_lst = [0]
    lst = list(map(int, input().split()))
    theme_lst.extend(lst)
    dp = [0 for _ in range(len(theme_lst))]
    ans = LIS(0, theme_lst, dp)
    answer.append(ans-1)
for i in answer:
    print(i)
    