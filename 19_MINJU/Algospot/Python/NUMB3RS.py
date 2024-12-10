import sys

input = sys.stdin.readline


answer = []
T = int(input())
for _ in range(T):
    n, d, p = map(int, input().split())
    lst = []
    for _ in range(n):
        tempt_lst = []
        input_lst = list(map(int, input().split()))
        for i in range(len(input_lst)):
            if input_lst[i] == 1:
                tempt_lst.append(i)
        lst.append(tempt_lst)
    t = int(input())
    ans_lst = list(map(int, input().split()))
    dp = [0 for _ in range(n)]
    dp[p] = 1
    for _ in range(d):
        new_dp = [0 for _ in range(n)]
        for idx, pro in enumerate(dp):
            size = len(lst[idx])
            for k in lst[idx]:
                new_dp[k] += pro*(1/size)
        for idx, val in enumerate(new_dp):
            dp[idx] = val
    answer_lst = [dp[val] for idx, val in enumerate(ans_lst)]
    # for k in dp:
    #     print(k, end= ' ')
    # print()
    answer.append(answer_lst)
for k in answer:
    for i in k:
        print(round(i,10), end=' ')
    print()
    