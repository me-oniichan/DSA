#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;

        for(string&s : wordDict) dict.insert(s);
        int size = s.size();
        // vector<vector<int>> dp(size, vector<int>(20));
        vector<bool> visited(size);

        queue<int> q;

        while(!q.empty()){
            string substr="";
            int i = q.front();
            q.pop();

            if(visited[i]) continue;
            for(int j=0; j < 20; j++){
                if(i+j >= size) break;
                substr.push_back(s[i+j]);
                if(dict.count(substr)){
                    if(i+j == size-1) return true;
                    q.push(i+j+1);
                }
            }
            visited[i] = true;
            
        }
        return false;

    }
};