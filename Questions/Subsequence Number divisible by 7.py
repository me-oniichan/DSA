#PRoblem statement: https://www.codechef.com/MAY222D/problems/SUB7NUM/

m = 1e9 +7
tc = int(input())
for x in range(tc):
    n = int(input())
    arr = input().split(' ')
    dyn = [[0]*7 for i in range(n+1)]
    dyn[0][0] = 1
    for i in range(n):
        l = len(arr[i])
        pow = 10**l
        for j in range(7):
            num = (j*pow+int(arr[i]))%7
            dyn[i+1][j] = (dyn[i][j] + dyn[i+1][j])%m
            dyn[i+1][num] = (dyn[i][j] + dyn[i+1][num])%m
    
    print(int(dyn[n][0]-1+m)%int(m))
