import sys

def fence(lst,left,right):
    if left == right:
        return lst[left]
    mid = (left+right)//2
    left_max = fence(lst, left, mid)
    right_max = fence(lst, mid+1, right)
    mid_max = lst[mid]
    mid_answer = lst[mid]
    count = 1
    l_id = mid-1
    r_id = mid+1
    while l_id >= left or r_id <= right:
        if l_id < left:
            count += 1
            mid_max = min(mid_max, lst[r_id]) 
            mid_answer = max(mid_answer, mid_max*count)
            r_id += 1
        elif r_id > right:
            count += 1
            mid_max = min(mid_max, lst[l_id])
            mid_answer = max(mid_answer, mid_max*count)
            l_id -= 1
        else:
            if lst[l_id] > lst[r_id]:
                count += 1
                mid_max = min(mid_max, lst[l_id])
                mid_answer = max(mid_answer, mid_max*count)
                l_id -= 1
            else:
                count += 1
                mid_max = min(mid_max, lst[r_id])
                mid_answer = max(mid_answer, mid_max*count)
                r_id += 1
    return max(left_max, mid_answer, right_max)
    
    
    

input = sys.stdin.readline
T = int(input())
answer = list()
for _ in range(T):
    N = int(input())
    lst = list(map(int, input().split()))
    ans = fence(lst, 0, len(lst)-1)
    answer.append(ans)
for k in answer:
    print(k)