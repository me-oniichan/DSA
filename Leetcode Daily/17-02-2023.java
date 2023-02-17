/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=Integer.MAX_VALUE;
    int prev=-100000;
    void inorder(TreeNode node){
        if(node==null) return;
        inorder(node.left);
        ans = Math.min(ans, node.val-prev);
        prev = node.val;
        inorder(node.right);
    }
    public int minDiffInBST(TreeNode root) {
        inorder(root);
        return ans;
    }
}