//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m[128]={0};
        for (char i : s) m[i]++;
        for (char i : t){
            if (m[i] == 0) return false;
            else m[i]--;
        }

        for(int i : m){
            if (i != 0) return false;
        }

        return true;
    }
}; 
 
int main(){
    
 
return 0;
}