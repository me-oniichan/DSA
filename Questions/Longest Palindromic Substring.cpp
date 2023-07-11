#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int anslen=1, size = s.size(), beg=0;
        vector<vector<int>> dp(size, vector<int>(size));
        dp[0][0]=1;
        for(size_t i=1; i < size; i++){
            dp[i][i] = 1;
            if(s[i]==s[i-1]){
                dp[i-1][i]=1;
                anslen=2;
                beg=i-1;
            }
        }

        for(int len=1; len < size; len++){
            for(int i=1; i < size-len; i++){
                if(s[i]==s[len+i] && dp[i+1][i+len-1]) {
                    dp[i][i+len] = dp[i+1][len+i-1]+1;
                    if(anslen < len){
                        anslen=len;
                        beg=i;
                    }
                }
            }
        }
        return s.substr(beg, anslen);
    }
};