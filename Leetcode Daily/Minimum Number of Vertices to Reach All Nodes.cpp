#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> m(n);
        for(auto i : edges){
            m[i[1]] = 1;
        }
        for(int i=0; i < n; i++){
            if(m[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}