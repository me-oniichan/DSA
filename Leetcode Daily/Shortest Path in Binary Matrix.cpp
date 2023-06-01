#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
         if(grid[0][0] || grid[n-1][n-1]) return -1;
        q.push({0, 0});
        grid[0][0]=1;
        while(!q.empty()){
            auto & p= q.front();
            if(p.first == n-1 && p.second == n-1) return grid[p.first][p.second];

            if(p.first > 0 && p.second >0 && grid[p.first-1][p.second-1]==0){
                grid[p.first-1][p.second-1] = grid[p.first][p.second]+1;
                q.push({p.first-1, p.second-1});
            }
            if(p.first > 0 && p.second < n-1 && grid[p.first-1][p.second+1]==0){
                grid[p.first-1][p.second+1]=grid[p.first][p.second]+1;
                q.push({p.first-1, p.second+1});
            }
            if(p.first < n-1 && p.second > 0 && grid[p.first+1][p.second-1]==0){
                grid[p.first+1][p.second-1]=grid[p.first][p.second]+1;
                q.push({p.first+1, p.second-1});
            }
            if(p.first < n-1 && p.second < n-1 && grid[p.first+1][p.second+1]==0){
                grid[p.first+1][p.second+1]=grid[p.first][p.second]+1;
                q.push({p.first+1, p.second+1});
            }
            if(p.first > 0 && grid[p.first-1][p.second]==0){
                grid[p.first-1][p.second]=grid[p.first][p.second]+1;
                q.push({p.first-1, p.second});
            }
            if(p.first < n-1 && grid[p.first+1][p.second]==0){
                grid[p.first+1][p.second]=grid[p.first][p.second]+1;
                q.push({p.first+1, p.second});
            }
            if(p.second > 0 && grid[p.first][p.second-1]==0){
                grid[p.first][p.second-1]=grid[p.first][p.second]+1;
                q.push({p.first, p.second-1});
            }
            if(p.second < n-1 && grid[p.first][p.second+1]==0){
                grid[p.first][p.second+1]=grid[p.first][p.second]+1;
                q.push({p.first, p.second+1});
            }
            q.pop();
        }
        return -1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++) cin>>v[i][j];
    }
    cout<< Solution().shortestPathBinaryMatrix(v);
}