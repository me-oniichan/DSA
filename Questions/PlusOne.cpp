#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(auto i = digits.rbegin(); i!=digits.rend(); i++){
            if(*i==9) *i = 0;
            else{
                *i = *i+1;
                break;
            }
        }
        if(digits[0]==0) digits.insert(digits.begin(), 1);

        return digits;
    }
}; 
 
int main(){


 
return 0;
}