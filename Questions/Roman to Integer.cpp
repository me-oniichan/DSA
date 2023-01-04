//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/878/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int romanToInt(string s) {
        int num = 0, pred = 0;
        unordered_map<char, int> letters;
        letters.insert({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});

        for(int i = s.size()-1; i >=0; i--){
            if (pred > letters[s[i]]) num-=letters[s[i]];
            else num+= letters[s[i]];
            pred = letters[s[i]];
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