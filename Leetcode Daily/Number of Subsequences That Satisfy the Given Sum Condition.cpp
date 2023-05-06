#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        const int mod = 1e9+7;

        vector<int> pow(nums.size());
        pow[0]=1;
        for(int i=1; i < nums.size(); i++) pow[i] = (pow[i-1]*2)%mod;

        int i=0, j=nums.size()-1;
        for(; i<=j; i++){
            if(nums[i]+nums[j] <= target){
                ans+= pow[j-i];
                ans%=mod;
                i++;
            }else j--;
        }

        return ans;
    }
};