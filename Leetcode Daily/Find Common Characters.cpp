#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        array<int, 26> maps;
        maps.fill(words.size());
        for(auto s : words){
            array<int, 26> internalmap;
            for(char c : s) internalmap[c-'a']++;
            for(int i=0; i < 26; i++) maps[i] = min(internalmap[i], maps[i]);
            internalmap.fill(0);
        }
        
        vector<string> ans;
        for(int i=0; i < 26; i++){
            for(int j=0; j < maps[i]; j++){
                ans.push_back(string(1, i+'a'));
            }
        }
        return ans;
    }

};
