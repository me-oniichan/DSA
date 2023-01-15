#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n);
        for(auto&i : matrix) i.resize(n);

        for(auto q : queries){
            matrix[q[0]][q[1]]+=1;
            if(q[2]+1 < n) matrix[q[2]+1][q[1]]-=1;
            if(q[3]+1 < n && q[2]+1 < n) matrix[q[2]+1][q[3]+1]+=1;
            if(q[3]+1 < n) matrix[q[0]][q[3]+1]-=1;
        }

        for(auto&i : matrix){
            for(int j =1; j < n; j++) i[j]+=i[j-1];
        }

        for(int i = 0; i < n; i++){
            for(int j =1; j < n; j++) matrix[j][i]+=matrix[j-1][i];
        }

        return matrix;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}