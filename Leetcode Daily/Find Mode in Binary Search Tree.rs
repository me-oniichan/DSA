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
use std::cmp::Ordering;
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn inorder(node: Option<&Rc<RefCell<TreeNode>>>, prev: &mut i32, maxcount: &mut i32, cur_count: &mut i32, ans: &mut Vec<i32>){
        if let Some(n) = node{
            let cur = n.borrow();
            
            Solution::inorder(cur.left.as_ref(), prev, maxcount, cur_count, ans);
            
            match cur.val.cmp(prev) {
                Ordering::Equal => {
                    *cur_count += 1;

                    if cur_count == maxcount{
                        ans.push(cur.val);
                    }
                    else if cur_count > maxcount{
                        *ans = vec![cur.val];
                        *maxcount = *cur_count;
                    }
                    
                },
                Ordering::Less | Ordering::Greater =>{
                    *cur_count = 1;
                    *prev = cur.val;

                    if *maxcount == 1{
                        ans.push(cur.val);
                    }
                }
            }
                
            Solution::inorder(cur.right.as_ref(), prev, maxcount, cur_count, ans);

        }
    }

    pub fn find_mode(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut prev = -1;
        let mut maxcount = 0;
        let mut cur_count = 0;
        let mut ans = Vec::new();

        Solution::inorder(root.as_ref(), &mut prev, &mut maxcount, &mut cur_count, &mut ans);

        ans
    }
}
