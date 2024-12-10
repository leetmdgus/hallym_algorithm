import sys

input = sys.stdin.readline

def divide_conquer(idx, i, j, lst, ch):
    if i > j:
        return
    if idx <= 1:
        if ch == 0:
            for k in range(i,j+1):
                print(lst[idx][k], end='')
        else:
            for k in range(i,j+1):
                if k == 2: print('-',end='')
                else : print(lst[idx][k], end='')
        return
    length = 2
    # print(length,'pre check')
    for _ in range(idx):
        length = length*2 + 1
    # print(length, 'after check')
    length //= 2
    # print(length,i,j, 'length check')
    # length = length // 2 + 1
    if j < length:
        divide_conquer(idx-1,i,j,lst, 0)
    elif i > length:
        divide_conquer(idx-1,i-length-1,j-length-1,lst, 1)
    else:
        divide_conquer(idx-1,i,length-1,lst, 0)
        if ch == 0 : print('+',end='')
        else : print('-', end='')
        divide_conquer(idx-1,0,j-length-1,lst, 1)    
T = int(input())
answer = []





for _ in range(T):
    n, p, l = map(int, input().split())
    lst = ["FX","FX+YF"]
    divide_conquer(n,p-1,p+l-2,lst,0)
    print()
    