#Problem Statement: https://www.codechef.com/problems/STUDVOTE
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    votes = [0]*n
    count = 0
    disqualify = []
    for i in range(n):
        if (arr[i] != i+1 and arr[i] not in disqualify): votes[arr[i]-1]+=1
        elif (arr[i] == i+1): disqualify.append(i+1);
    for i in range(n):
        if (votes[i] >= k and i+1 not in disqualify): count+=1
    print(count)
