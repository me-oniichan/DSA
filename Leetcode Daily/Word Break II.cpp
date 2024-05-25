#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(s.size() + 1);
        dp[0] = {""};
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dict.count(word)) {
                    for (string sentence : dp[j]) {
                        dp[i].push_back(sentence + (sentence == "" ? "" : " ") + word);
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
