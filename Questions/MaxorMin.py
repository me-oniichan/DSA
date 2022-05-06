#Problem Statement: https://www.codechef.com/problems/MAXORMIN
t = int(input())
for i in range(t):
    n = int(input())
    string = input()
    one, zero = string.count("1"), string.count("0")
    if one >= zero: print(1)
    else: print(0)