pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> (i32, i32){
        if let Some(n) = node{
            let cur = n.borrow();
            
            let (left_sum, left_num) = Self::dfs(&cur.left, ans);
            let (right_sum, right_num) = Self::dfs(&cur.right, ans);

            let avg = (left_sum + right_sum + cur.val) as f64 / (left_num+right_num+1) as f64;

            if avg as i32 == cur.val{
                *ans+=1;
            }

            return (left_sum+right_sum+cur.val, left_num+right_num+1);

        }
        (0, 0)
    }
    pub fn average_of_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;
        Self::dfs(&root, &mut ans);
        
        ans
    }
}
