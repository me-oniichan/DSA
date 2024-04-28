#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans = 0;
        vector<int> dp(26);
        
        for (auto c : s){
            int first = c-k-'a';
            int last = c+k-'a';    
            for(int i = max(0, first); i <= min(last, 25); i++){
                dp[c-'a'] = max(dp[c-'a'], dp[i]);
            }

            dp[c-'a']++;
            ans = max(ans, dp[c-'a']);
        }

        return  ans;
    }
};
