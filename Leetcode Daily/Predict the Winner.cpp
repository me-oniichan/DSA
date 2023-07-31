#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size));

        for(size_t i = 0; i < size; i++) dp[i][i] = nums[i];

        for(size_t diff = 1; diff < size; diff++){
            for(size_t left = 0; left < size-diff; left++){
                size_t right = left+diff;
                dp[left][right] = max(nums[left] - dp[left+1][right], nums[right] - dp[left][right-1]);
            }
        }
        return dp[0][size-1] >=0;
    }
};