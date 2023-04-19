#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

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

    void solve(TreeNode* root, bool wasRight, int pathLength, int& longestPathLength){

        if (root == NULL)
            return;

        longestPathLength = max(pathLength, longestPathLength);

        if (wasRight)
            solve(root->left, false, pathLength + 1, longestPathLength);
        else 
            solve(root->left,  false, 1, longestPathLength);

        if (!wasRight)
            solve(root->right, true, pathLength + 1, longestPathLength);
        else 
            solve(root->right,  true, 1, longestPathLength);
    }

    int longestZigZag(TreeNode* root) {
        
        int pathLength = 0;
        int longestPathLength = 0;
        bool wasRight = true;

        solve(root, wasRight, pathLength, longestPathLength);

        return longestPathLength;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}