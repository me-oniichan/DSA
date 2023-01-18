//Problem Statement : Maximum Sum Circular Subarray

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cursum = 0, maxsum = nums[0], curmin = 0, minsum = nums[0], sum=0;
        for(int&i : nums){
            cursum+=i;
            maxsum = max(cursum, maxsum);
            cursum = max(0, cursum);
            curmin+=i;
            curmin = min(0, curmin);
            minsum = min(minsum, curmin);

            sum+=i;
        }

        return sum == minsum? maxsum : max(maxsum, sum-minsum);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}