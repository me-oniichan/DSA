#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1);
        const int M = 1000000007;
        dp[0]=1;
        for(int i=1; i <= high; i++){
            dp[i] += (i>one)? dp[i-one]: 0;
            dp[i] += (i>zero)? dp[i-zero]: 0;
            dp[i]%=M;
        }
        int ans = 0;
        for(int i=low;i <=high;i++){
            ans += dp[i];
            ans%=M;
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