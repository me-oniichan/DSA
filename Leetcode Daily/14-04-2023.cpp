#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rs = s; int len = s.size();
        reverse(s.begin(), s.end());
        cout<<s<<' '<<rs;

        vector<vector<int>> dp(len+1, vector<int>(len+1));

        for(int i = len-1; i >=0; i--){
            for(int j = len-1; j >=0; j--){
                dp[i][j] = (rs[i] == s[j])? 1+dp[i+1][j+1]: max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}