#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int start=0, end=0, size = nums.size();
        int sum=0;
        for(; end < size; end++){
            sum+=nums[end];
            while(sum >= target){
                sum-=nums[start];
                ans = min(ans, end-start+1);
                start++;
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};