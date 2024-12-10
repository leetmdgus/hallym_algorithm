import sys

input = sys.stdin.readline

T = int(input())
answer = []
for _ in range(T):
    n = int(input())
    lst = []
    hap_lst = []
    dp = []
    for i in range(1,n+1):
        tempt = list(map(int, input().split()))
        lst.append(tempt)
        dp_lst = []
        hap_tempt = []
        for j in range(i):
            dp_lst.append(10000000000000)
            hap_tempt.append(0)
        hap_lst.append(hap_tempt)
        dp.append(dp_lst)
    dp[0][0] = 1
    hap_lst[0][0] = lst[0][0]
    for i in range(n-1):
        for j in range(i+1):
            tmp = hap_lst[i][j] + lst[i+1][j]
            if tmp > hap_lst[i+1][j]:
                dp[i+1][j] = dp[i][j]
                hap_lst[i+1][j] = tmp
            elif tmp == hap_lst[i+1][j]:
                dp[i+1][j] += dp[i][j]
                
            tmp = hap_lst[i][j] + lst[i+1][j+1]
            if tmp > hap_lst[i+1][j+1]:
                dp[i+1][j+1] = dp[i][j]
                hap_lst[i+1][j+1] = tmp
            elif tmp == hap_lst[i+1][j+1]:
                dp[i+1][j+1] += dp[i][j]
    max_ = max(hap_lst[n-1])
    ans = 0
    for i in range(n):
        if hap_lst[n-1][i] == max_:
            ans += dp[n-1][i]
    answer.append(ans)
for k in answer:
    print(k)
            
    
    