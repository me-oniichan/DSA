#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        stack<int> mst;
        for(int i: nums){
            if (mst.empty() || mst.top() > i) mst.push(i);
            else {
                while (!mst.empty()){
                    score += mst.top();
                    mst.pop();
                    if (!mst.empty()){
                        mst.pop();
                    }
                }
            }
        }

        while (!mst.empty()){
            score += mst.top();
            mst.pop();
            if (!mst.empty()){
                mst.pop();
            }
        }
        return score;
    }
};
