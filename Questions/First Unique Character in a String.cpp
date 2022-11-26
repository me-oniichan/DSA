//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(char i : s) map[i]++;
        for(int i = 0; i < s.length(); i++){
            if (map[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
 
int main(){

 
return 0;
}