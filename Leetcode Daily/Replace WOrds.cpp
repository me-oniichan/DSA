#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;
        for(auto word: dictionary) dict.insert(word);
        string ans = "";
        string word = "";
        sentence.push_back(' '); 
        for(int i=0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                if(word.size() > 0){
                    ans += word+" ";
                }
                word.clear();
            }
            else {
                word.push_back(sentence[i]);
                if(dict.count(word)){
                    ans += word+" ";
                    word = "";
                    while(i < sentence.size() && sentence[i] != ' ') i++;
                }
            }
        }
        if (ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};
