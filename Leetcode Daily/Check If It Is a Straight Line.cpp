#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        set<double> s;
        int size= coordinates.size();
        for(int i = 1; i < size;i++){
            double slope = coordinates[i][0] == coordinates[i-1][0]? INT_MAX : (coordinates[i][1] - coordinates[i-1][1])/(double)(coordinates[i][0] - coordinates[i-1][0]);

            s.insert(slope);
            if(s.size()>1) return false;
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}