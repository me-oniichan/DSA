#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int size = intervals.size();
        vector<int> dp(size+1);

        for(int i = size-1; i >=0; i--){
            int index = lower_bound(intervals.begin()+i, intervals.end(), intervals[i][1], [](vector<int>&a, int b){
                return a[0] < b;
            }) - intervals.begin();
            dp[i] = min(dp[index] + index-i-1, dp[i+1]+1);
        }
        return dp[0];
    }
};