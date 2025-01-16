#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<long long> diffarr(n);
        priority_queue<int, vector<int>, greater<int>> topn;
        priority_queue<int> bottomn;
        long long leftsum = 0, rightsum=0;
        for(int i=0; i < n; i++){
            bottomn.push(nums[i]);
            leftsum+=nums[i];
            topn.push(nums[2*n+i]);
            rightsum += nums[2*n+i];
        }
        long long slsum = leftsum;
        long long ans = leftsum - rightsum;

        for(int i=0; i < n; i++){
            int ofindx = n+i;
            int top = bottomn.top();
            if (top > nums[ofindx]){
                leftsum -= top;
                leftsum += nums[ofindx];
                bottomn.pop();
                bottomn.push(nums[ofindx]);
            }
            diffarr[i]=leftsum;
        }
        for(int i: diffarr){
            cout<<i<<" ";
        }
        for(int i = 2*n-1; i>=n; i--){
            ans = min(ans, diffarr[i-n] - rightsum);
            int top = topn.top();
            if (nums[i] > top){
                rightsum -= top;
                rightsum += nums[i];
                topn.pop();
                topn.push(nums[i]);
            }
        }
        return min(ans, slsum - rightsum);
    }
};
