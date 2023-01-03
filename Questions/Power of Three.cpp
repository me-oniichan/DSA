//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/745/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)return false;
        double num = log(n)/log(3);
        if (abs(num - round(num)<=0.00000001)) return true;
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}