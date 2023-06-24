#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int size = nums.size();
        vector<unordered_map<int, size_t>> dp(size); // {diff, length}
        size_t ans = 0;

        for(size_t i=0; i < size; i++){
            for(size_t j=0; j < i; j++){
                int diff = nums[i] - nums[j];
                dp[i][diff] = max(dp[j][diff], 1u)+1u;
                ans = max(ans, dp[i][diff]);
            }
        }
        return (int) ans;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}