//Problem Statement : https://leetcode.com/problems/non-decreasing-subsequences/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    set<vector<int>> ans;
    void makeseq(int i, vector<int>& maxseq, vector<int> vec){
        if(i==maxseq.size()){
            if(vec.size() >1) ans.insert(vec);
            return;
        };

        makeseq(i+1, maxseq, vec);
        if(vec.size()==0 || vec.back()<=maxseq[i]){
            vec.push_back(maxseq[i]);
            makeseq(i+1, maxseq, vec);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        makeseq(0, nums, vector<int>());

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}