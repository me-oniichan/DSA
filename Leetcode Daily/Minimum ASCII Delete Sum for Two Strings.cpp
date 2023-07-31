#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        size_t size1= s1.size(), size2 = s2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1));
        int maxsum=0;
        for(size_t i=0; i < size1; i++) maxsum+=s1[i];
        for(size_t i=0; i < size2; i++) maxsum+=s2[i];

        for(size_t i =0; i < size1; i++){
            for(size_t j=0; j < size2; j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = dp[i][j] + s1[i]; 
                }
                else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
                
            }
        }

        return maxsum - 2*dp[size1][size2];
    }
};