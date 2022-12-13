//Problem Statement : https://leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int row = 1;row<m; row++){
            for(int col = 0;col<m;col++){
                int first = col>0? matrix[row-1][col-1] : INT_MAX;
                int second = matrix[row-1][col];
                int third = col+1<m? matrix[row-1][col+1]: INT_MAX;

                matrix[row][col] += min({first, second, third});
            }
        }
        return *min_element(matrix[m-1].begin(), matrix[m-1].end());
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}