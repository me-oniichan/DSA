#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0;
        vector<int> flip(n, 0);
        int flipCount = 0;
        for (int i = 0; i < n; i++) {
            if (i >= K) {
                flipCount -= flip[i - K];
            }
            if ((A[i] + flipCount) % 2 == 0) {
                if (i + K > n) {
                    return -1;
                }
                flipCount++;
                flip[i] = 1;
                ans++;
            }
        }
        return ans;
    }
};
