#[derive(Debug, PartialEq, Eq)]
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
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, is_left: bool) -> i32 {
        if let Some(node) = node {
            let node = node.borrow();
            if node.left.is_none() && node.right.is_none() {
                if is_left {
                    return node.val;
                }
            }
            return Self::dfs(&node.left, true) + Self::dfs(&node.right, false);
        }
        0
    }
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, false)
    }
}
