#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int util (vector<int>& nums, int target,int idx){
        if(target!=0 && idx>=nums.size()) return 0;

        if(target ==0 && idx== nums.size()) return 1;

        return util(nums,target-nums[idx],idx+1)+util(nums,target+nums[idx],idx+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return util(nums,target,0);
    }
};
