#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> old(n, vector<double>(n));
        vector<vector<double>> cur(n, vector<double>(n));
        queue<pair<int, int>> q({{row, column}, {-1,-1}});
        old[row][column] = 1;
        vector<pair<int, int>> direc({{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}});

        for(int i=0; i < k; i++){
            for(int r=0; r < n; r++){
                for(int c=0; c < n; c++){
                 
                    for(auto[a,b] : direc){
                        int row = a+r, col = b+c;
                        if(row>=0 && row < n && col>=0 && col<n){
                            cur[r][c]+=old[row][col]/8;
                        }
                    }

                }
            }
            old = cur;
            for(auto &v : cur){
                for(double &i : v) i=0;
            }
        }
        
        
        double ans = 0;
        for(auto &r : old){
            for(double d : r){
                ans+=d;
            }
        }
        return ans;
    }
};