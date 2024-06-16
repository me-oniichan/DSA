#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        sort(A.begin(), A.end());
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(A[i] <= A[i-1]) {
                ans += A[i-1] - A[i] + 1;
                A[i] = A[i-1] + 1;
            }
        }
        return ans;
    }
};
