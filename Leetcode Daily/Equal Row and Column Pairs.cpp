#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_multiset<string> rows;
        for(auto& i : grid){
            string s;
            for(int j : i) s+=to_string(j)+" ";
            s.pop_back();
            rows.insert(s);
        }
        int size = grid.size(), ans=0;
        for(size_t i=0; i < size; i++){
            string s;
            for(int j = 0; j < size; j++){
                s+=to_string(grid[j][i])+" ";
            }
            s.pop_back();
            ans+=rows.count(s);
        }

        return ans;
    }
};