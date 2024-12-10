import sys
input = sys.stdin.readline


    

V, E = map(int, input().split())

vertex = []
for i in range(V+1):
    vertex.append([1000000000 for _ in range(V+1)])
    

for i in range(E):
    a, b, c = map(int, input().split())
    vertex[a][b] = c

check = [0 for _ in range(V+1)]

    
for k in range(1, V+1):
    for i in range(1, V+1):
        for j in range(1, V+1):
            if vertex[i][j] > vertex[i][k] + vertex[k][j]:
                vertex[i][j] = vertex[i][k] + vertex[k][j]

min_ = 1000000000
for i in range(1, V+1):
    min_ = min(vertex[i][i], min_)

if min_ == 1000000000:
    print(-1)
else:
    print(min_)
