//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int rob(vector<int>& nums) {
        int sum = 0, sum2=0, i = 0;
        while(i < nums.size()-1){
            if (nums[i] > nums[i+1]){
                sum+=nums[i];
                sum2+=nums[i];
                i+=2;
            }
            else{
                sum+=nums[i+1];
                sum2+=nums[i+1];
                i+=3;
            }
        }
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}