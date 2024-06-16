#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxNum = 0;
        int patches = 0;
        for (int i = 0; maxNum < n;) {
            if (i < nums.size() && nums[i] <= maxNum + 1) {
                maxNum += nums[i++];
            } else {
                maxNum += maxNum + 1;
                patches++;
            }
        }
        return patches;
    }
};
