#problem Statement: https://www.codechef.com/problems/LAPTOPREC
t = int(input())
for _ in range(t):
    n = int(input())
    arr= list(map(int, input().split(" ")))
    freq = [[0, i+1] for i in range(10)]
    for i in range(n):
        freq[arr[i]-1][0]+=1
    freq = sorted(freq)
    if (freq[9][0] == freq[8][0]): print("CONFUSED")
    else: print(freq[9][1])