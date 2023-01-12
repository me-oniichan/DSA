//Problem Statement : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> dfs(int n, int p, vector<int>&res, string& lables){
        vector<int> chars(26);
        char c = lables[n];
        
        if(tree[n].size() == 0){
            res[n] = chars[c - 'a'] =1;
            return chars;
        }

        for(int i : tree[n]){
            if(p == i) continue;
            int j = 0;
            for(int f : dfs(i, n, res, lables)){
                chars[j]+=f;
                j++;
            };
        }

        chars[c-'a']+=1;
        res[n] = chars[c-'a'];
        return chars;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        tree.resize(labels.size());
        for(auto &i : edges){
            tree[i[0]].push_back(i[1]);
            tree[i[1]].push_back(i[0]);
        }

        vector<int> res(labels.size());
        dfs(0,0,res, labels);
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}