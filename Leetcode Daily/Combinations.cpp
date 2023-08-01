#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int k, n;
    vector<vector<int>> ans; 
    void backtrack(int i, vector<int> &v){
	   if(i > n) return;
	   v.push_back(i);
	   if(v.size() == k) ans.push_back(v);
	   else backtrack(i+1,v);
	   v.pop_back();
	   backtrack(i+1, v);
    }
    vector<vector<int>> combine(int n, int k) {
	   this->k = k; this->n = n;
	   vector<int> v;
	   backtrack(1, v);
	   return ans;
    }
}; 
