#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1));

        for(int i=1; i <= size1; i++){
            for(int j=1; j <= size2; i++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int ans=0;
        for(int i=size1, j=size2; i > 0 && j > 0;){
            if(s1[i-1] == s2[j-1]){
                ans+=s1[i-1];
                i--; j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
    }
};