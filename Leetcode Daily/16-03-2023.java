import java.util.HashMap;

class TreeNode {
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
    TreeNode root = null;
    HashMap<Integer, Integer> m = new HashMap<>();
    TreeNode setNode(int val, int index, TreeNode node){
        if(node==null) return new TreeNode(val);

        if(m.get(node.val) < index) node.right = setNode(val, index, node.right);
        else node.left = setNode(val, index, node.left);
        return node;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int j=0;
        for(int i : inorder) m.put(i, j++);
        
        int size = postorder.length;
        for(int i= size-1; i>=0; i--){
            root = setNode(postorder[i], m.get(postorder[i]), root);
        }

        return root;
    }
}