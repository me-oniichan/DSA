#Prolem Statement: https://www.codechef.com/submit/DOUBLEDDIST

t = int(input())
for _ in range(t):
    n = int(input())
    arr = sorted(list(map(int, input().split())))
    prev = arr[1] - arr[0]
    #check distances
    for i in range(1,n-1):
        if (prev/2 == arr[i+1]-arr[i] or prev*2 == arr[i+1]-arr[i]): prev = arr[i+1]-arr[i]
        else:
            print("NO")
            break
    else:
        print("YES")
