//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/

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
    TreeNode* reqNode(vector<int>& nums, int low, int high){
        if (low> high) return NULL;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(nums[mid], reqNode(nums, low, mid-1), reqNode(nums, mid+1, high));
        return node;
    };
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return reqNode(nums, 0, nums.size()-1);
    }
};
 
 
int main(){
    
 
return 0;
}