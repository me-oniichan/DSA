#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size();
        if(k==0) return nums;
        if(2*k >= size) return vector<int>(size, -1);
        long long sum =0;
        
        for(int i =0; i <= 2*k; i++){
            sum+=nums[i];
        }
        vector<int> ans(size, -1);
        int r = k*2+1;
        nums.push_back(0);
        for(int i = k; i < size -k; i++){
            ans[i] = sum/r;
            sum+= nums[i+k+1] - nums[i-k];
        }
        return ans;
    }
};