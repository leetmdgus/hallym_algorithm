n = int(input())
cnt = 0
if(n < 5):
    n -= 3
    cnt += 1
if(n >= 5):
    if(n % 5 == 0):
        cnt = n // 5
        n = n % 5
    elif(n % 3 == 0):
        while(n > 0):
            n -= 3
            cnt += 1
            if(n % 5 == 0):
                cnt += (n // 5)
                n = n % 5
    else:
        while(n > 0):
            n -= 3
            cnt += 1
            if(n % 5 == 0):
                cnt += n // 5
                n = n % 5
if n != 0:
    cnt = -1
print(cnt)