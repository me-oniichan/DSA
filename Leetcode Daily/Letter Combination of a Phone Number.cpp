#include <bits/stdc++.h>
using namespace std;

array<string, 8> maps({"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});

class Solution {
public:
    int size;
    vector<string> ans;
    string str;
    void backtrack(int i, string& s){
	   if(i==size){
		  ans.push_back(str);
		  return;
	   }
	   int digit = s[i] - '2';
	   for(size_t j=0; j < maps[digit].size(); j++){
		  str[i] = maps[digit][j];
		  backtrack(i+1, s);
	   }
    }
    vector<string> letterCombinations(string digits) {
        size = digits.size();
	   if(size==0) return ans;
        str.resize(size);
	   backtrack(0, digits);
	   return ans;
    }
};
