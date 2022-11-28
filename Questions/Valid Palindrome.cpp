//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for( char i : s){
            if (i>=65 && i <=90) s2.push_back(tolower(i));
            else if((i>=97 && i<=122) || (i>=48 && i<=57)) s2.push_back(i);
        }

        int size = s2.length();
        for(int i=0; i < size/2; i++){
            if(s2[i] != s2[size-i-1]) return false;
        }
        return true;
    }
}; 
 
int main(){
    
 
return 0;
}