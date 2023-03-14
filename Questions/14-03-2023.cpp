#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void dfs(TreeNode *root,vector <string> &v,string curr){
        if(!root)
            return;
        if(!root->left && !root->right)
        {   
            int x=root->val;
            v.push_back(curr+to_string(x));
            return;
        }
        int x=root->val;
        dfs(root->left,v,curr+to_string(x));
        dfs(root->right,v,curr+to_string(x));
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        vector <string> v;
        dfs(root,v,"");
        for(auto i:v)
            res+=stoi(i);
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}