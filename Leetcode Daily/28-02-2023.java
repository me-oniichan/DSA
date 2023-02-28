import java.util.*;

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
    List<TreeNode> ans = new ArrayList<>();
    Map<String, Integer> m = new HashMap<>();
    Map<Integer, Integer> count = new HashMap<>();
    int postOrder(TreeNode node){
        if(node==null) return 0;
        String triplet = postOrder(node.left)+" "+node.val+" "+postOrder(node.right);
        if(m.containsKey(triplet)){
            int id = m.get(triplet);
            int c = count.get(id);
            if(c==0) {
                ans.add(node);
                count.put(id, c+1);
            }

        }
        else{
            m.put(triplet, m.size()+1);
            count.put(m.size(), 0);
        }
        return m.get(triplet);
    }
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        postOrder(root);
        return ans;
    }
}