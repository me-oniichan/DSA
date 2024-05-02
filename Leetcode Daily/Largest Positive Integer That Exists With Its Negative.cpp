#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int maxK = INT_MIN;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                if(mp.find(-nums[i]) != mp.end()) {
                    maxK = max(maxK, abs(nums[i]));
                }
            }
        }
        return maxK;
    }
};
