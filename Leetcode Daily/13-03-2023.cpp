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
    bool check(TreeNode* node1, TreeNode* node2){
        if (!node1 && !node2) return true;
        else if(!node1 || !node2) return false; 

        if (node1->val != node2->val) return false;
        return check(node1->left, node2->right) && check(node1->right, node2->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}