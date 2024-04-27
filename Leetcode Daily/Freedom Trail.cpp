#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (ring[j] != key[i - 1]) continue;
                for (int k = 0; k < n; k++) {
                    if (dp[i - 1][k] == INT_MAX) continue;
                    int diff = abs(j - k);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(diff, n - diff));
                }
            }
        }
        return *min_element(dp[m].begin(), dp[m].end()) + m;
    }
};
