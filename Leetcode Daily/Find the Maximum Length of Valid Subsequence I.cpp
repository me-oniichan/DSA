#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int parity[2] = {0, 0};
        int lastpairty[2] = {0, 1};
        int chainlen[2] = {0, 0};
        for (int num : nums){
            int paritynum = num%2;
            parity[paritynum]++;
            if (lastpairty[0] != paritynum){
                chainlen[0]++;
                lastpairty[0] = paritynum;
            }
            if (lastpairty[1] != paritynum){
                chainlen[1]++;
                lastpairty[1] = paritynum;
            }
        }

        return max(
            max(chainlen[0], chainlen[1]),
            max(parity[0], parity[1])
        );
    }
};
