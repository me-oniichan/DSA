//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[3] = {0};
        for(int i: nums){
            dp[0] = max(i+dp[2], dp[1]);
            dp[2] = dp[1];
            dp[1] = dp[0];
        }
        return dp[0];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}