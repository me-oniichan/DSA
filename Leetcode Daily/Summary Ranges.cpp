#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        int checkpoint = nums[0];
        nums.push_back(-1);
        int size = nums.size();
        vector<string> ans;
        for(int i=1; i < size; i++){
            if((long long)nums[i]-nums[i-1]==1) continue;

            if(checkpoint == nums[i-1]) ans.push_back(to_string(checkpoint));
            else ans.push_back(to_string(checkpoint) + "->"+ to_string(nums[i-1]));
            checkpoint = nums[i];
        }
        return ans;
    }
};