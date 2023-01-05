//Problem Statement : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int end=points[0][1], point=1;
        for(auto &i : points){
            if (i[0] > end) {
                point++;
                end = i[1];
            }
            else end = min(i[1], end);
        }
        return point;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}