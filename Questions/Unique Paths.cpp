#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = 0;

        for(int i=1; i < n; i++){
            for(int j=0; j <m; j++){
                dp[j][i]+= j>0? dp[j-1][i] : 0;
                dp[j][i]+= i>0? dp[j][i-1] : 0;
            }
        }
        return dp[m-1][n-1];
    }
};