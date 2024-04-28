#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int r = 1; r < rows; r++){
            for(int c=0; c < cols; c++){
                int left = c>0? *min_element(grid[r-1].begin(), grid[r-1].begin()+c): INT_MAX;
                int right = c+1<cols? *min_element(grid[r-1].begin()+c+1, grid[r-1].end()): INT_MAX;
                grid[r][c]+= min(left, right);
            }
        }

        int ans = INT_MAX;
        for(int i : grid.back()){
            ans =  min(ans, i);
        }

        return ans;
    }
};
