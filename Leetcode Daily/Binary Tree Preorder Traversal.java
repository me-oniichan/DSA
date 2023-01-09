import java.util.*;;
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    List<Integer> list = new ArrayList<Integer>();
    public void preorder(TreeNode node){
        if (node == null) return;
        list.add(node.val);
        preorder(node.left);
        preorder(node.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        preorder(root);
        return list;
    }
}