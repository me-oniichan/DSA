#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(auto &row : obstacleGrid) for(int &i : row) i*=-1;

        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        obstacleGrid[0][0]=1;
        for(int i=0; i<rows; i++){
            for(int j=0; j < cols; j++){
                if(obstacleGrid[i][j]==-1) continue;

                if(i>0 && obstacleGrid[i-1][j] != -1) obstacleGrid[i][j]+=obstacleGrid[i-1][j];
                if(j>0 && obstacleGrid[i][j-1] != -1) obstacleGrid[i][j]+=obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[rows-1][cols-1]==-1? 0 : obstacleGrid[rows-1][cols-1];
    }
};