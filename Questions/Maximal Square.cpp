#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> grid(rows+1, vector<int>(cols+1));

        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++) grid[i+1][j+1] = (matrix[i][j]=='1');
        }
        int maxm=0;
        for(int i=1; i <= rows; i++){
            for(int j=1; j <= cols; j++){
                if(grid[i][j]!=0) {
                    grid[i][j] += min(grid[i-1][j], min( grid[i-1][j-1], grid[i][j-1]));
                    maxm = max(maxm, grid[i][j]);
                }
            }
        }
        return maxm*maxm;
    }
};