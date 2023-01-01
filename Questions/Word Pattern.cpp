//Problem Statement : https://leetcode.com/problems/word-pattern/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hmap;
        unordered_set<string> se;
        s.push_back(' ');
        string word; int size = pattern.size(), i = 0;
        for(char c : s){
            if (c == ' '){
                if (!hmap.count(pattern[i%size])) hmap[pattern[i%size]] = word;
                else if (hmap[pattern[i%size]] != word) return false;
                word = "";
                i++;
            }
            else word.push_back(c);
        }
        if (i != pattern.size()) return false;
        for(auto val : hmap){
            if(!se.count(val.second)) se.insert(val.second);
            else return false;
        }

        return true;
    }
};