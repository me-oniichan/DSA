//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/

#include <iostream>
using namespace std;

class Solution {
public:
    
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    int trim(string &s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            else return i;
        }
        return s.size()-1;
    }
    int myAtoi(string s) {
        if (s.size() == 0) return 0;
        
        long num = 0, mfactor= 1;

        int index = trim(s);
        if (s[index] == '-'){
            mfactor = -1;
            index++;
        }
        else if(s[index] == '+') index++;

        for(int i = index; i< s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                num*=10;
                num+=(s[i]-'0');
                if (num >= INT_MAX && mfactor==1) return INT_MAX;
                else if((num>= (long)INT_MAX+1) && mfactor == -1) return INT_MIN;
            }
            else{
                break;
            }

        }
        return num*mfactor;
        
    }
};
 
int main(){

 
return 0;
}