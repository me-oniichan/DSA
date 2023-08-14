use std::collections::BinaryHeap;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut pq  = BinaryHeap::from(nums);

        for i in (1..k).rev(){
            pq.pop();
        }

        match pq.peek() {
            Some(v) => *v,
            None => 0,
        }
    }
}
