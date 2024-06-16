#include <array>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        
        array<array<int, 2>, 4> direction = {{{1,0}, {-1,0}, {0,1}, {0,-1}}};
        vector<pair<int, int>> req;
        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto cell: direction){
                int nr = r+cell[0];
                int nc = c+cell[1];

                if(nr>=0 && nr<grid.size() && nc>=0 && nc < grid[0].size() && grid[nr][nc] == grid[r][c]){
                    if (!visited[nr][nc]) {
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
                else {
                    req.push_back({r,c});
                }
            }
        }

        for(auto [r,c]: req){
            grid[r][c] = color;
        }

        return grid;
    }
};
