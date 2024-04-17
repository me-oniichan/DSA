use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;

type Node = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn add_one_row(root: Node, val: i32, mut depth: i32) -> Node {
        if depth == 1 { return Some(Rc::new(RefCell::new(TreeNode{val, left: root, right: None}))); }
        let queue = Self::get_nodes_at_depth(root.clone(), depth);
        queue.into_iter().filter(|node| node.is_some()).for_each(|node| {
            let node = node.unwrap();
            let mut value = node.borrow_mut();
            value.left = Some(Rc::new(RefCell::new(TreeNode{val, left: value.left.clone(), right: None})));
            value.right = Some(Rc::new(RefCell::new(TreeNode{val, left: None, right: value.right.clone()})));
        });
        root
    }

    fn get_nodes_at_depth(root: Node, mut depth: i32) -> VecDeque<Node> {
        let mut queue = VecDeque::new();
        queue.push_back(root.clone());
        while !queue.is_empty() && depth > 2 {
            for _ in 0..queue.len() {
                let curr = queue.pop_front().unwrap().unwrap();
                let node = curr.borrow();
                if let Some(left) = node.left.clone() {
                    queue.push_back(Some(left.clone()));
                } 
                if let Some(right) = node.right.clone() {
                    queue.push_back(Some(right.clone()));
                }
            }
            depth -= 1;
        }
        queue
    }
}
