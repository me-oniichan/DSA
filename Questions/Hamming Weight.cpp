//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/565/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            count++;
            n&=(n-1);
        }
        return count;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}