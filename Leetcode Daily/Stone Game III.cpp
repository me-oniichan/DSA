#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int size = stoneValue.size();
        int dp[4] = {0};

        for(int i = size-1; i>=0; i--){
            dp[i%4] = stoneValue[i] - dp[(i+1)%4];
            if(i+2 <= size) dp[i%4] =  max(dp[i % 4], stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 4]);
            if (i + 3 <= size) dp[i % 4] = max(dp[i % 4], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 4]);
        }
        if (dp[0] < 0) return "Bob";
        else if (dp[0] > 0) return "Alice";
        return "Tie";

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}