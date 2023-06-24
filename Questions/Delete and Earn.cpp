#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(*max_element(nums.begin(), nums.end())+1);
        for(int i: nums) dp[i]++;

        int prev1=0, prev2 = 0;
        
        for(int i=0; i < dp.size(); i++){
            int cost = max(dp[i]*i+prev2, prev1);
            prev2 = prev1;
            prev1 = cost;
        }
        return prev1;
    }
};