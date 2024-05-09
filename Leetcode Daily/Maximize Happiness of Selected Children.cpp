#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = happiness[0];
        for (int i=1; i < k; i++) {
            ans += max(happiness[i]-i, 0);
        }

        return ans;
    }
};
