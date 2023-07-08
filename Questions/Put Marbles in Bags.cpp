#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        size_t size = weights.size();
        for(size_t i=0; i < size-1; i++){
            weights[i]+=weights[i+1];
        }

        weights.pop_back();
        sort(weights.begin(), weights.end());

        long long ans=0;
        for(int i=0; i < k-1; i++){
            ans+=weights[size-2-i] - weights[i];
        }
        return ans;
    }
};