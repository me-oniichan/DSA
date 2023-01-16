#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newint;
        for(auto &i:intervals){
            if(i[1]<newInterval[0])newint.push_back(i);
            else if(newInterval[1]<i[0]){
                newint.push_back(newInterval);
                newInterval=i;
            }
            else{
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }    
        }
        newint.push_back(newInterval);
        return newint;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}