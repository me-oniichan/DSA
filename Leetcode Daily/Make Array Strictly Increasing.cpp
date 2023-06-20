#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& ar1, vector<int>& ar2) {
        int n = ar1.size(), m = ar2.size();
        sort(ar2.begin(), ar2.end());
        int dp[n][n+1];
        dp[0][0] = ar1[0];
        dp[0][1] = (ar2[0] < ar1[0]) ? ar2[0] : INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i+1; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i-1][j] < ar1[i]) {
                    dp[i][j] = min(dp[i][j], ar1[i]);
                }
                dp[i][j+1] = min(dp[i][j+1], _find(ar2, dp[i-1][j], 0, m-1));
            }
        }
        for (int i = 0; i <= n; i++) {
            if (dp[n-1][i] < INT_MAX) {
                return i;
            }
        }
        return -1;
    }
    
    int _find(const vector<int>& ar, int target, int lo, int hi) {
        if (lo == hi) {
            if (target >= ar[lo]) return INT_MAX;
            else return ar[lo];
        }
        int mid = (lo + hi + 1) / 2;
        if (ar[mid] > target) {
            if (target >= ar[mid-1]) {
                return ar[mid];
            } else {
                return _find(ar, target, lo, mid-1);
            }
        } else {
            return _find(ar, target, mid, hi);
        }
    }
};
