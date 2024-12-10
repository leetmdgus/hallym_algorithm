import sys

input = sys.stdin.readline


def overlap_str(a,b):
    length = min(len(a), len(b))
    for i in range(length-1,-1,-1):
        cnt = 0
        for j in range(i+1):
            if a[len(a)-i-1+j] == b[j]:
                cnt += 1
            else:
                cnt = -1
                break
        if cnt == i+1:
            return cnt
    return 0

def direct_dfs(idx, ch, lst, over_lap, count,dp):
    if ch == (1<<len(lst))-1:
        return 0
    else:
        if ch in dp[idx]:
            return dp[idx][ch]
        dp[idx][ch] = 0
        for i in range(len(lst)):
            tempt = 1 << i
            if (tempt & ch) != 0:
                continue
            else:
                dp[idx][ch] = max(dp[idx][ch], over_lap[idx][i]+direct_dfs(i, ch+(1<<i),lst,over_lap,count+1,dp))
        return dp[idx][ch]
    
def reconstruct(idx, ch, lst, over_lap, count, dp):
    if ch == 0+(1<<len(lst))-1:
        return lst[idx]
    else:
        for i in range(len(lst)):
            tempt = 1 << i
            if (tempt & ch) != 0:
                continue 
            else:
                Ifused = direct_dfs(i, ch+(1<<i), lst,over_lap, count+1,dp)
                if Ifused+over_lap[idx][i] == dp[idx][ch]:
                    return lst[idx]+reconstruct(i,ch+(1<<i), lst, over_lap, count+1, dp)[over_lap[idx][i]::]
                    
T = int(input())
answer = []
for _ in range(T):
    k = int(input())
    str_lst = [input().strip() for _ in range(k)]
    str_lst.insert(0,'')
    k += 1
    dp = []
    for _ in range(k):
        dp.append(dict())
    over_lap = []
    for _ in range(k):
        tempt_list = [0 for _ in range(k)]
        over_lap.append(tempt_list)
    check = [0 for _ in range(k)]
    for i in range(k):
        for j in range(k):
            if i!=j and str_lst[j] in str_lst[i]:
                over_lap[i][j] = 0
                if str_lst[j] == str_lst[i]:
                    check[max(i,j)] = 1
                else:
                    check[j] = 1
            elif i!=j:
                over_lap[i][j] = overlap_str(str_lst[i], str_lst[j])
    ch = 0
    check[0] = 1
    route = []
    for idx, i in enumerate(check):
        ch += (i << idx)

    rtr = direct_dfs(0, ch, str_lst, over_lap, 1, dp)
    ans = reconstruct(0,ch, str_lst, over_lap, 1, dp)
    answer.append(ans)
for k in answer:
    print(k)