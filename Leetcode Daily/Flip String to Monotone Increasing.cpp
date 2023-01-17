//Problem Statement : 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = count(s.begin(), s.end(), '0');
        int ones = 0;
        int minflips = INT_MAX;
        for(char & c : s){
            if(c=='0') zeros--;
            int sum = zeros+ones;
            if (sum < minflips) minflips = sum;
            if (c=='1') ones++;
        }
        return minflips;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}