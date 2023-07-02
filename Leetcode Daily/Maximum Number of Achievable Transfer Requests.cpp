#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> in;
    vector<int> out;
    int ans=0, n;
    void backtrack(int i, int achived, vector<vector<int>>&requests){
        if(i==requests.size()){
            for(size_t i=0; i < n; i++){
                if(in[i]!=out[i]) return;
            }
            ans = max(ans, achived);
            return;
        }
        out[requests[i][0]]++; in[requests[i][1]]++;
        backtrack(i+1, achived+1, requests);
        out[requests[i][0]]--; in[requests[i][1]]--;
        backtrack(i+1, achived, requests);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        in.resize(n);
        out.resize(n);
        this->n = n;
        backtrack(0,0, requests);
        return ans;
    }
};