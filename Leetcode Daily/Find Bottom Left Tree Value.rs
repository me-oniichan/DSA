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
    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = std::collections::VecDeque::new();
        queue.push_back(root.unwrap());
        let mut result = 0;
        while !queue.is_empty() {
            let mut next_queue = std::collections::VecDeque::new();
            let mut left = 0;
            for node in queue {
                left = node.borrow().val;
                if let Some(right_node) = &node.borrow().right {
                    next_queue.push_back(right_node.clone());
                }
                if let Some(left_node) = &node.borrow().left {
                    next_queue.push_back(left_node.clone());
                }
            }
            result = left;
            queue = next_queue;
        }
        result
    }
}
