//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/722/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = (nums.size()*(nums.size()+1))/2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return total - sum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}