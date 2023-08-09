#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
	   int ans=1;
	   vector<int> dp(size, 1);
	   for(int i=1; i < size; i++){
		  for(int j=i-1; j >= 0; j--){
			 if(nums[j] < nums[i]){
				dp[i] = max(dp[j]+1, dp[i]);
			 }
		  }
		  ans= max(dp[i], ans);
	   }
	   return ans;
    }
};
