//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxindex(string &s1, string &s2, int size){
        for(int i = 0; i < size; i++){
            if (s1[i] != s2[i]) return i-1;
        }
        return size-1;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs[0].size();
        for(int i = 0; i < strs.size()-1; i++){
                int size2 = strs[i].size();
                size = maxindex(strs[i-1], strs[i], min(size, size2));
        }
        return strs[0].substr(size);
    }
}; 
 
int main(){

 
return 0;
}