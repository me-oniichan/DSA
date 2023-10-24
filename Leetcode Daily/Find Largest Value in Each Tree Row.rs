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
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = Vec::new();
        if let Some(root) = root{
            let mut q = Vec::new();
            ans.push(root.borrow().val);
            q.push(root);

            while !q.is_empty() {
                let mut lq = Vec::new();
                for i in q{
                    let elem = i.borrow();
                
                    if let Some(left) = &elem.left{
                        lq.push(left.clone());
                    }
                    if let Some(right) = &elem.right{
                        lq.push(right.clone());
                    }
                }
                match lq.iter().max_by_key(|x| x.borrow().val) {
                    None => {},
                    Some(x) => {
                        ans.push(x.borrow().val);
                    }
                }
                q = lq;
            } 

        }
        ans
    }
}
