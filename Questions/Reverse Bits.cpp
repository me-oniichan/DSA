//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/648/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num=0;

        for(int i =0; i < 32; i++){
            num<<=1;
            num|=(n&1);
            n>>=1;
        }
        return num;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}