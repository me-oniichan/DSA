#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    bool check(string& word, unordered_set<string> &s){
        const int length = word.length();
        vector<bool> dp(length + 1);
        dp[0] = true;
        for (int i = 1; i <= length; ++i) {
            for (int j = (i == length ? 1 : 0); !dp[i] && j < i; ++j) {
                dp[i] = dp[j] && s.count(word.substr(j, i - j));
            }
        }
        return dp[length];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> m(words.begin(), words.end());
        vector<string> ans;
        for(auto&word : words){
            if(check(word, m)) ans.push_back(word);
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}