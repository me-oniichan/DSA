#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size(), maxm=1;
        vector<int> subseqlen(size,1);
        vector<int> times(size,1);

        for(int i=0; i < size; i++){
            int cur = subseqlen[i];
            for(int j=i-1; j >=0; j--){
                if(nums[j] < nums[i]){
                    if(subseqlen[j]+1 > subseqlen[i]){
                        subseqlen[i] = subseqlen[j]+1;
                        times[i]=times[j];
                        maxm = max(maxm, subseqlen[i]);
                    }
                    else if(subseqlen[j]+1 == subseqlen[i]){
                        times[i]+=times[j];
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i < size; i++){
            // cout<<subseqlen[i]<<" ";
            if(maxm == subseqlen[i]) ans+=times[i];
        }
        // cout<<endl;
        // for(int i=0; i < size; i++){
        //     cout<<times[i]<<" ";
        // }
        return ans;
    }
};