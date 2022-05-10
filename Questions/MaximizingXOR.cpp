//Problem Statement: https://www.hackerrank.com/challenges/maximizing-xor/problem
#include <bits/stdc++.h>

using namespace std;

int maximizingXor(int l, int r) {
    if (l == r) return 0;
    return (1<<int(log2(l^r)+1))-1;
}

int main()
{
  int l, r;
  cin>>l>>r;
  cout<< maximizingXor(l,r)<<endl;
  return 0;
}
