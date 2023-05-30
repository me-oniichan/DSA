#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size));
        sort(cuts.begin(), cuts.end());

        for(int i=2; i < size; i++){
            for(int l=0; l < size-i; l++){
                int r = l+i;
                int curval = INT_MAX;
                for(int k=l+1; k <r; k++) curval = min(curval, dp[l][k]+dp[k][r]+cuts[r]-cuts[l]);
                dp[l][r] = curval;
            }
        }
        return dp[0][size-1];
    }
};