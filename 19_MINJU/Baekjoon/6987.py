import sys

input = sys.stdin.readline
answer = []
def backtrack(i,j,lst, count, visited):
    global ans
    if ans == 0: 
        return
    if count == 15:
        ans = 0
        return
    if j == 0:
        tmp = [0,0,0]
        for k in range(i,6):
            for l in range(3):
                tmp[l] += lst[k][l]
        if tmp[0] != tmp[2]:
            return
        if tmp[1] % 2 == 1:
            return
    if i == 5 and j==5:
        return
    if i==j:
        backtrack(i, j+1, lst, count,visited) 
    else:
        if lst[i][1] > 0 and lst[j][1] > 0 and visited[i][j] == 0:
            lst[i][1] -= 1
            lst[j][1] -= 1
            visited[i][j] = 1
            visited[j][i] = 1
            if j == 5: backtrack(i+1, 0, lst, count+1,visited)
            else : backtrack(i, j+1, lst, count+1,visited)
            visited[i][j] = 0
            visited[j][i] = 0             
            lst[i][1] += 1
            lst[j][1] += 1      
            
            
        if lst[i][0] > 0 and lst[j][2] > 0 and visited[i][j] == 0:
            lst[i][0] -= 1
            lst[j][2] -= 1
            visited[i][j] = 1
            visited[j][i] = 1
            if j == 5: backtrack(i+1, 0, lst, count+1,visited)
            else : backtrack(i, j+1, lst, count+1,visited)
            visited[i][j] = 0
            visited[j][i] = 0             
            lst[i][0] += 1
            lst[j][2] += 1
            
            
        if lst[i][2] > 0 and lst[j][0] > 0 and visited[i][j] == 0:
            lst[i][2] -= 1
            lst[j][0] -= 1
            visited[i][j] = 1
            visited[j][i] = 1
            if j == 5: backtrack(i+1, 0, lst, count+1,visited)
            else : backtrack(i, j+1, lst, count+1,visited)
            visited[i][j] = 0
            visited[j][i] = 0             
            lst[i][2] += 1
            lst[j][0] += 1
            
            
        if j == 5: backtrack(i+1, 0, lst, count,visited)
        else : backtrack(i, j+1, lst, count,visited)
                
                
        
    
    

for _ in range(4):
    ans = 100000000
    tempt = list(map(int, input().split()))
    lst = []
    for i in range(0, 18, 3):
        lst.append([tempt[i], tempt[i+1], tempt[i+2]])
    lst.sort()
    if sum(tempt) != 30: 
        answer.append(0)
        continue
    check = 0
    # for i in lst:
    #     if sum(i) != 5:
    #         answer.append(0)
    #         check = 1
    #         break
    if check == 1:
        continue
    visited = []
    for i in range(6):
        visited.append([0 for _ in range(6)])
    backtrack(0, 0, lst, 0, visited)
    if ans == 0:
        answer.append(1)
    else:
        answer.append(0)
for k in answer:
    print(k, end= ' ')
    
    
    
    
    