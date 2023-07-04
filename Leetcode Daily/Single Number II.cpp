#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;

        for(int i=0; i < 32; i++){
            int count=0;
            for(int num : nums){
                count+= (num<<i)&1;
            }
            if(count%3==1) ans|=(1<<i);
        }
        return ans;
    }
};