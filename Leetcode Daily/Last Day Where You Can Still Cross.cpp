#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    int left, right;
    bool dfs(int mid, vector<vector<int>>&cells){
        for(int i=left; i<=mid; i++) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        for(int i=mid+1; i<=right; i++) grid[cells[i][0]-1][cells[i][1]-1] = 0;

        stack<pair<int, int>> st;
        unordered_set<int> visited;
        int col = grid[0].size(), row = grid.size();

        for(int i = 0; i < col; i++){
            if( grid[0][i]==0 && !visited.count(i)){
                st.push({0,i});
                visited.insert(i);

                while(!st.empty()){
                    auto p = st.top();
                    st.pop();
                    if(p.first == row-1) return true;
                    for(auto &v : vector<pair<int, int>>({{p.first-1, p.second}, {p.first, p.second+1}, {p.first+1, p.second}, {p.first, p.second-1}})){
                        if(v.first >= 0 && v.second >= 0 && v.first < row && v.second < col && grid[v.first][v.second] == 0 && !visited.count(v.first*col + v.second)){
                            visited.insert(v.first*col + v.second);
                            st.push({v.first, v.second});
                        }
                    }

                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        grid.resize(row, vector<int>(col));

        left = 0; right = cells.size()-1;

        while(left < right){
            int mid = (left+right)/2;
            if(dfs(mid, cells)){
                left = mid+1;
            }
            else right = mid;
        }

        return left;

    }
};