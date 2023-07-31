#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left=1, right = accumulate(batteries.begin(), batteries.end(), 0)/n;

        while(left < right){
            long long mid = right - (right - left)/2, extra = 0;
            
            for(long long i : batteries) extra+= min(mid, i);

            if(extra >= n*mid){
                left = mid;
            }else right = mid-1;
        }
        return left;
    }
};