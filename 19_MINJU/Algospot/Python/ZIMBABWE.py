import sys

input = sys.stdin.readline

T = int(input())
def Mapping_array(check):
    rtr = 0
    for i in range(10):
        rtr += (16**i)*check[i]
    return rtr

def ZIMBABWE(check, dp,m, count):
    if count == 0:
        return 0
    any = Mapping_array(check)
    if any in dp:
        return any
    dp[any] = [0 for k in range(m)]
    cnt = 0
    for i in range(10):
        if check[i] > 0:
            check[i] -= 1
            cnt = i*count
            tempt = cnt%m
            count //= 10
            
            val = ZIMBABWE(check, dp,m, count)
            
            if val == 0:
                dp[any][tempt] = 1
            else:
                for j in range(m):
                    dp[any][(j+tempt)%m]= (dp[any][(j+tempt)%m] + dp[val][j])%1000000007
            count *= 10
            cnt = 0
            check[i] += 1
    return any

def find(idx, lst, check, dp, m, count, dp2):
    if idx == len(lst):
        return 0
    any = Mapping_array(check)
    dp2[any] = [0 for _ in range(m)]
    for i in range(10):
        if check[i] > 0 and i < lst[idx]:
            check[i] -= 1
            cnt = i*count
            count //= 10
            val = ZIMBABWE(check, dp, m, count)
            
            count *= 10
            check[i] += 1
            tempt = cnt%m
            if val == 0:
                dp2[any][tempt] = 1
            else:
                for j in range(m):
                    dp2[any][(j+tempt)%m]= (dp2[any][(j+tempt)%m] + dp[val][j])%1000000007
        elif check[i] > 0 and i == lst[idx]:
            cnt = lst[idx]*count
            count //= 10
            check[i] -= 1
            
            val = find(idx+1, lst, check, dp, m, count, dp2)
            
            count *= 10
            tempt = cnt%m
            check[i] += 1
            if val == 0:
                continue
            else:
                for j in range(m):
                    dp2[any][(j+tempt)%m]= (dp2[any][(j+tempt)%m] + dp2[val][j])%1000000007
    return any             
answer = []
for _ in range(T):
    e, m = map(int, input().split())
    tmp = e
    lst = []
    while e > 0:
        lst.append(e%10)
        e = e//10
    lst.reverse()
    check = [0 for _ in range(10)]
    dp = dict()
    dp2 = dict()
    dp[0] = [0 for _ in range(m)]
    for i in lst:
        check[i] += 1
    rtr = find(0, lst, check, dp, m, 10**(len(lst)-1),dp2)
    answer.append(dp2[rtr][0])
    # any = ZIMBABWE(check,dp,m,10**(len(lst)-1))
    # print(dp[any][0])
for k in answer:
    print(k)