//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/601/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back(vector<int>{1});

        for(int i = 2; i <=numRows; i++){
            triangle.push_back(vector<int>(i));
            vector<int> &ref = triangle[i-1];

            ref[0] = 1;
            for(int j = 1; j < triangle[i-2].size(); j++){
                ref[j] = triangle[i-2][j]+triangle[i-2][j-1];
            }
            ref[i-1] = 1;

        }
        return triangle;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}