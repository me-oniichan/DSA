import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if (root == null)
            return ans;
        boolean dire = false; // false for right to left;
        Deque<TreeNode> q1 = new LinkedList<TreeNode>();
        q1.add(root);
        ans.add(Arrays.asList(root.val));
        while (!q1.isEmpty()) {
            Deque<TreeNode> q2 = new LinkedList<TreeNode>();
            while (!q1.isEmpty()) {
                TreeNode node = q1.poll();
                if (node.left != null)
                    q2.add(node.left);
                if (node.right != null)
                    q2.add(node.right);
            }
            q1 = q2;
            if (!q2.isEmpty()) {
                List<Integer> temp = new ArrayList<Integer>();
                if (dire) {
                    for (TreeNode n : q2)
                        temp.add(n.val);
                } else {
                    Iterator<TreeNode> i = q2.descendingIterator();
                    while (i.hasNext()) {
                        temp.add(i.next().val);
                    }
                }
                ans.add(temp);
            }
            dire = !dire;
        }

        return ans;
    }
}