#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int size = piles.size();
        vector<vector<int>>dp(size+1, vector<int>(k+1));
        for(int i=1;i <= size; i++){
            for(int coin=0; coin<=k; coin++){
                int cursum=0;
                int lim = min((int)piles[i-1].size(), coin);
                for(int curcoins =0; curcoins <= lim; curcoins++){
                    if(curcoins>0) cursum+= piles[i-1][curcoins-1];
                    dp[i][coin] = max(dp[i][coin], dp[i - 1][coin - curcoins] + cursum);
                }
            }
        }
        return dp[size][k];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}