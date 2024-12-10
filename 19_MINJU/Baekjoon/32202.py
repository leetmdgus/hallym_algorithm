import sys
input = sys.stdin.readline

N = int(input())
lst = [0,3,8]
for i in range(3,N+1):
    tempt = (lst[i-1]*2+lst[i-2]*2)%1000000007
    lst.append(tempt)
print(lst[N])