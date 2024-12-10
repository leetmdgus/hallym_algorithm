import sys

def direct_dfs(before, idx, word_list, next_wordlist, confuse_matrix, dp, m, dic, dp_lst):
    if idx == len(word_list):
        return 1
    if dp[idx][before] != -1:
        return dp[idx][before]
    rtr = 0
    for i in range(m):
        tmp = confuse_matrix[i][dic[word_list[idx]]] * next_wordlist[before][i] * direct_dfs(i,idx+1,word_list, next_wordlist, confuse_matrix, dp, m, dic, dp_lst)
        if dp[idx][before] < tmp:
            dp[idx][before] = tmp
            dp_lst[idx][before] = i        
    return dp[idx][before]
            
                
        
    
    

input = sys.stdin.readline
m, q = map(int, input().split())
word_list = list(input().split())

first_p = list(map(float, input().split()))

next_wordlist = []
dic = dict()
for idx, k in enumerate(word_list):
    dic[k] = idx
for i in range(m):
    tempt_list = list(map(float, input().split()))
    next_wordlist.append(tempt_list)

confuse_list = []
for _ in range(m):
    tempt_lst = list(map(float, input().split()))
    confuse_list.append(tempt_lst)

answer_list = []
for _ in range(q):
    tempt_list = list(input().split())
    answer_list.append(tempt_list)
for i in answer_list:
    ans = 0
    idx = 0
    dp = []
    dp_lst = []
    length = int(i.pop(0))
    for k in range(length):
        dp.append([-1 for _ in range(m)])
        dp_lst.append([0 for _ in range(m)])
    for j in range(m):
        tmp = confuse_list[j][dic[i[0]]]*first_p[j]*direct_dfs(j, 1, i, next_wordlist, confuse_list, dp, m ,dic, dp_lst)
        if tmp > ans:
            ans = tmp
            idx = j
    print(word_list[idx], end= ' ')
    for i in range(1,length):
        idx = dp_lst[i][idx]
        if i != length-1 : print(word_list[idx], end= ' ')
        else : print(word_list[idx])