//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/566/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], max = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(sum>=0){
                sum+=nums[i];
                if (sum>max) max = sum;
            }
            else if(nums[i] > max) max = nums[i];
        }
        return max;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}