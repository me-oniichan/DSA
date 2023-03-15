import java.util.*;;

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
    int prev = -1; boolean ans=true;
    Set<Integer> s = new TreeSet<>();
    void dfs(TreeNode node, int h){
        if(node==null){
            s.add(h);
            if(s.size()>2){
                ans=false;
                return;
            }
            else if(prev==-1){
                prev=h; return;
            }
            int diff = prev-h;
            prev=h;
            if(diff==0 || diff==1) return;
            ans=false;
            return;
        }
        if(ans){
            dfs(node.left, h+1);
            dfs(node.right, h+1);
        }
    }
    public boolean isCompleteTree(TreeNode root) {
        dfs(root, 0);
        return ans;
    }
}