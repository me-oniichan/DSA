//Problem Statement : https://leetcode.com/problems/number-of-good-paths/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int find(vector<int>& y,int i) {
		if(i==y[i]) return i;
		y[i]=find(y,y[i]);
		return y[i];
	}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int paths = 0;
        paths+=vals.size();
        vector<int> count(paths, 1);
        vector<int> un(paths);
        for(int i=0; i<paths; i++) un[i]=i;

        sort(edges.begin(), edges.end(), [&](const vector<int>& x, const vector<int>& y) {
           return max(vals[x[0]], vals[x[1]]) < max(vals[y[0]], vals[y[1]]);
        });

        for(auto &i : edges){
            int x = find(un,i[0]);
            int y = find(un, i[1]);
            if(vals[x] == vals[y]){
                paths+=(count[x]*count[y]);
                un[y] = x;
                count[y]+=count[x];
            }
            else{
                if (vals[x] > vals[y]) un[y] = x;
                else un[x] = y;
            }
        }
        return paths;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}