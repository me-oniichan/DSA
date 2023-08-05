#include <bits/stdc++.h>
#include <cstddef>
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
    vector<TreeNode*> generateTrees(int n) {
	   vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
	   for(size_t i=1; i <=n; i++){
		  dp[i][i].push_back(new TreeNode(i));
	   }
	   for(int treesize=2; treesize <= n; treesize++){
		  for(int start=1; start <= n-treesize+1; start++){
			 int end = start+treesize-1;
			 for(int i = start; i <= end; i++){
				vector<TreeNode*> lTree =
                        i>start ? dp[start][i - 1] : vector<TreeNode*>({NULL});
                    vector<TreeNode*> rTree =
                        i<end ? dp[i + 1][end] : vector<TreeNode*>({NULL});

				for(auto left : lTree){
				    for(auto right : rTree){
					   TreeNode* root = new TreeNode(i, left, right);
					   dp[start][end].push_back(root);
				    }
				}
			 } 
		  } 
	   }
	   return dp[1][n];
    }
};
