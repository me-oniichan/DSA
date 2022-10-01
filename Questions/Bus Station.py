#Problem statement: https://www.hackerrank.com/contests/k21-26sept1st-oct/challenges/bus-station

n = int(input())
frnds = list(map(int, input().split()))
maxsum = sum(frnds)
maxelem = max(frnds)
ans = []
def isvalid(group):
    sum = 0
    for i in range(n):
        if sum < group: sum+= frnds[i]
        if sum > group: return
        elif sum == group:
            if i == n-1: ans.append(group)
            sum = 0

i = 1
while i*i <= maxsum:
    isvalid(i)
    if maxsum//i != i: isvalid(maxsum//i)
    i+=1

print(*sorted(ans))