#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0, winsize=0, zc=0;
        nums.push_back(0);
        int size = nums.size(), checkp=0;
        for(int i=0; i < size; i++){
            if(nums[i]==0){
                zc++;
                if(zc==1){
                    ans = max(ans, winsize);
                }
                else{
                    ans=max(ans, winsize-1);
                    zc=1;
                    winsize=i-checkp-1;
                }
                checkp = i;
            }
            winsize++;
        }
        if (ans==size-1) return size-2;
        return ans;
    }
};