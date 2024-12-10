import sys
def swap(lst):
    tmp = lst[0]
    lst[0] = lst[2]
    lst[2] = tmp
    
    tmp2 = lst[1]
    lst[1] = lst[3]
    lst[3] = tmp2

def div_comp(tempt):
    if len(tempt) == 1:
        print("SIDDUDD")
        return tempt
    idx = 0
    lst = ['' for _ in range(4)]
    # print(tempt)
    for i in range(4):
        if tempt[idx] == 'x':
            a,id = div_comp(tempt[idx+1::])
            idx += id
            idx += 1
            lst[i] = a
        else:
            lst[i] = tempt[idx]
            idx += 1
    swap(lst)
    rtr = 'x'
    for k in lst:
        rtr += k
    return rtr, idx
input = sys.stdin.readline
T = int(input())
ans = []
for _ in range(T):
    tempt = input()
    answer = ''
    tempt = tempt[0:len(tempt)-1]
    if len(tempt) == 1:
        answer = tempt
    else:
        answer,idx = div_comp(tempt[1:])
    ans.append(answer)
for k in ans:
    print(k) 
    




