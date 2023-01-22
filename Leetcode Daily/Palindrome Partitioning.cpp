#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)
class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    vector<string> curstrs;
    void backtrack(int i, string&s){
        if(i==s.length()) ans.push_back(curstrs);

        for(int j = i; j < s.length(); j++){
            if(s[i]==s[j] && (j-i <=2 || dp[i+1][j-1])){
                dp[i][j] = true;
                curstrs.push_back(s.substr(i, j-i+1));
                backtrack(j+1, s);
                curstrs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dp.assign(s.length(),vector<bool>(s.length(), false));

        backtrack(0, s);
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}