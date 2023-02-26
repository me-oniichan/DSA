#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length = word1.size(), width = word2.size();
        vector<vector<int>> dp(length+1, vector<int>(width+1));

        if(!length) return width;
        else if(!width) return length;

        //initiating dp
        for(int i = 1; i <= length; i++) dp[i][0]=i;
        for(int i = 1; i <= width; i++) dp[0][i]=i;

        for(int i = 1; i <= length; i++)
            for(int j = 1; j <= width; j++){
                int del = dp[i][j-1]+1;
                int ins = dp[i-1][j]+1;
                int rep = dp[i-1][j-1] + (word1[i-1]!=word2[j-1]);
                dp[i][j] = min(del, min(ins, rep));
            }

        return dp[length][width];   
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}