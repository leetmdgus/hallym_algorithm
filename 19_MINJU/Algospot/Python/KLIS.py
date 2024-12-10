import sys

input = sys.stdin.readline

def KLIS(idx, lst, dp, way_count, vertex_lst):
    if dp[idx] != 0:
        return dp[idx]
    rtr = 1
    for i in range(idx, len(lst)):
        if lst[i] > lst[idx]:
            tmp = KLIS(i, lst, dp, way_count, vertex_lst) + 1
            if tmp > rtr:
                rtr = tmp
                way_count[idx] = way_count[i]
                vertex_lst[idx] = [(lst[i], i)]
            elif tmp == rtr:
                way_count[idx] += way_count[i]
                vertex_lst[idx].append((lst[i], i))
    dp[idx] = rtr
    return dp[idx]

def find(idx, lst, way_count, vertex_lst, K, cnt):
    hap = 0
    if idx != 0:
        print(lst[idx], end =' ')
    for t in vertex_lst[idx]:
        a, b = t
        hap += way_count[b]
        if K <= hap:
            find(b, lst, way_count, vertex_lst, K-(hap-way_count[b]), cnt)
            break
    

T = int(input())
answer = []

for _ in range(T):
    N,K = map(int, input().split())
    theme_lst = [-1]
    input_lst = list(map(int, input().split()))
    theme_lst.extend(input_lst)
    lst = theme_lst
    dp = [0 for _ in range(len(lst))]
    way_count = [1 for _ in range(len(lst))]
    vertex_lst = []
    for _ in range(len(lst)):
        vertex_lst.append([])
    KLIS(0, lst, dp, way_count, vertex_lst)
    for k in vertex_lst:
        k.sort(key = lambda x : x[0])
    print(dp[0]-1)
    find(0, lst, way_count, vertex_lst, K, 0)
    print()
    # print(dp)
    # print(way_count)
    # print(vertex_lst)