//Problem Statement : https://leetcode.com/problems/delete-columns-to-make-sorted/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    bool sorted(int col, vector<string> &strs){
        for(int i = 0; i < strs.size()-1; i++){
            if (strs[i][col] > strs[i+1][col]) return false;
        }
        return true;
    };
    int minDeletionSize(vector<string>& strs) {
        int num = 0;
        for(int i = 0; i < strs[0].size(); i++){
            if (!sorted(i, strs)) num++;
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