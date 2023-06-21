#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getCost(long long elem, vector<int>&nums, vector<int>&cost){
        long long res = 0;
        for(int i=0; i < nums.size(); i++){
            res += abs(elem - nums[i])*cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int size = nums.size();
        long long ans = getCost(nums[0], nums, cost);

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while(left < right){
            int mid = (left+right)/2;
            long long c1 = getCost(mid, nums, cost), c2 = getCost(mid+1, nums, cost);
            ans = min(c1,c2);
            if(c1 <= c2){
                right=mid;
            }else{
                left = mid+1;
            }

        }
        return ans;
    }
};