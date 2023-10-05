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
    pub fn dfs(node: Option<Rc<RefCell<TreeNode>>>)->(i32, i32){
        if node == None{
            return (0,0);
        } 
        let node = node.as_ref().unwrap().borrow();
        
        
        let (ltake, nltake) = Solution::dfs(node.left);
        let (rtake, nrtake) = Solution::dfs(node.right);

        let take = node.val+nltake+nrtake;
        let ntake = ltake.max(nltake)+ rtake.max(nrtake);

        (take, ntake)


    }
    pub fn rob(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
       let (take, ntake) = Solution::dfs(root);

       take.max(ntake)
        
    }
}
