//Problem Statement : https://leetcode.com/problems/detect-capital/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital = 0;
        for(char i : word){
            if ('A'<=i && i<='Z') capital++;
        }

        if (capital == word.size() || !capital) return true;
        if (capital==1 && ('A'<= word[0]&& word[0]<='Z')) return true;
        return false;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}