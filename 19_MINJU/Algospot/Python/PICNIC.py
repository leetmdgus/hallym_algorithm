import sys
input = sys.stdin.readline

def count_pairings(n, adj_matrix,check):
    if (sum(check) == n):
        return 1
    for idx, visit in enumerate(check):
        if not visit:
            break
    first_node = idx
    count = 0
    for j in range(first_node+1, n):
        if (not check[j] and adj_matrix[first_node][j]):
            check[first_node] = True
            check[j] = True
            count += count_pairings(n, adj_matrix, check)
            check[first_node] = False
            check[j] = False
    return count


t = int(input().strip())
for _ in range(t):
    n, m = map(int, input().strip().split(" "))
    lst = []
    if m != 0:
        lst = list(map(int, input().strip().split()))
    adj_matrix = [[0] * n for _ in range(n)]
    check = [False]*n
    for i in range(m):
        u = lst[2*i]
        v = lst[2*i+1]
        adj_matrix[u][v] = adj_matrix[v][u] = 1
        
    print(count_pairings(n, adj_matrix, check))
