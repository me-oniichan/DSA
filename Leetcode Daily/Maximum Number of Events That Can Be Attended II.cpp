#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int size = events.size();
        vector<vector<int>> dp(k+1, vector<int>(size+1));

        sort(events.begin(), events.end());

        for(int i=size-1; i >= 0; i--){
            int reqidx = lower_bound(events.begin()+i+1, events.end(), events[i][1], [](vector<int>&a, int b){
                return a[0] <= b;                
            }) - events.begin();
            for(int j=1; j <= k; j++){
                dp[j][i] = max(dp[j][i+1], dp[j-1][reqidx] + events[i][2]);
            }
        }

        return dp[k][0];
    }
};