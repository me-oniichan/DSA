#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int size =questions.size();
        vector<long long> dp(size);
        dp[size-1] = questions[size-1][0];
        for(int i=size-2; i>=0;i--){
            int bp = questions[i][1]+i+1;
            dp[i] = questions[i][0] + ((bp<size)? dp[bp] : 0);
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};