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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth=0;
        unsigned long long minW=0, maxW = 0;
        queue<pair<TreeNode*, unsigned long long>> q({{root, 1}, {NULL, -1}});
        while(!q.empty()){
            auto & p = q.front();
            q.pop();
            if(p.first == NULL){
                maxWidth = max(maxWidth, (int)(maxW-minW));
                minW = 0;
                maxW=0;
                if(q.empty()) break;
                else q.push({NULL, -1});
            }else{
                if(minW == 0) minW = p.second;
                maxW = max(maxW, p.second);
                if(p.first->left != NULL) q.push({p.first->left, p.second*2-minW*2});
                if(p.first->right != NULL) q.push({p.first->right, p.second*2+1-minW*2});
            }
        }
        return maxWidth+1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}