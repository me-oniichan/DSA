#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q({root});

        vector<vector<int>> graph(501);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            if(node->left){
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right){
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }

        queue<array<int, 3>> gq({array<int, 3>({target->val, 0, -1})}); //node, distance, parent
        vector<int> ans;
        while(!gq.empty()){
            auto [node, dist, parent] = gq.front();
            gq.pop();
            if(dist==k){
                ans.push_back(node);
                continue;
            }
            for(int i : graph[node]){
                if(i==parent) continue;
                else gq.push({i, dist+1, node});
            }
        }
        return ans;
    }
};