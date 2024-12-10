import sys

def dfs(H,W, grid, a, b, ck, cj, count):
    print(count)
    if count == 0:
        return 1
    else:
        ret = 0
        for i in range(a, H):
            if a != i:
                b = 0
            for j in range(b, W):
                if grid[i][j] == '.':
                    # print('=====================')
                    # print(i,j)
                    # for tt in grid:
                    #     print(tt)
                    # print('=====================')
                    for k in range(4):
                        flag = True
                        for l in range(2):
                            nx = i + ck[k*2+l]
                            ny = j + cj[k*2+l]
                            if nx >= 0 and nx < H and ny >= 0 and ny < W and grid[nx][ny] == '.':
                                continue
                            else:
                                flag = False
                                break           
                        if flag:
                            grid[i][j] = '#'
                            for l in range(2):
                                nx = i + ck[k*2+l]
                                ny = j + cj[k*2+l]
                                grid[nx][ny] = '#'
                            ret += dfs(H,W,grid,i,j,ck,cj,count-3)        
                            grid[i][j] = '.'
                            for l in range(2):
                                nx = i + ck[k*2+l]
                                ny = j + cj[k*2+l]
                                grid[nx][ny] = '.'  
        return ret  
                

input = sys.stdin.readline
T = int(input())
for _ in range(T):
    H,W = map(int, input().strip().split())
    grid = []
    for _ in range(H):
        tempt = []
        tmp = input().strip()
        for i in tmp:
            tempt.append(i)
        grid.append(tempt)
    ck = [1,0,1,1,0,1,1,1]
    cj = [0,1,-1,0,1,1,0,1]
    count = 0
    for i in range(H):
        for j in range(W):
            if grid[i][j] == '.':
                count += 1
    if count%3 != 0 or count == 0:
        print(0)
    else: 
        a = -1
        b = 0
        answer = 0
        for i in range(H):
            for j in range(W):
                if grid[i][j] == '.':
                    a = i
                    b = j
                    break
            if a != -1:
                break
        for k in range(4):
            flag = True
            for l in range(2):
                nx = i + ck[k*2+l]
                ny = j + cj[k*2+l]
                if nx >= 0 and nx < H and ny >= 0 and ny < W and grid[nx][ny] == '.':
                    continue
                else:
                    flag = False
                    break
            if flag:
                grid[i][j] = '#'
                for l in range(2):
                    nx = i + ck[k*2+l]
                    ny = j + cj[k*2+l]
                    grid[nx][ny] = '#'
                answer += dfs(H,W,grid,i,j,ck,cj,count-3)     
                grid[i][j] = '.'   
                for l in range(2):
                    nx = i + ck[k*2+l]
                    ny = j + cj[k*2+l]
                    grid[nx][ny] = '.' 
        print(answer)