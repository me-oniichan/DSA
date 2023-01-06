//Problem Statement : https://leetcode.com/problems/maximum-ice-cream-bars/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ice = 0;
        for(int &i : costs){
            if (coins >= i){
                coins-=i;
                ice++;
            }
            else return ice;
        }
        return ice;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}