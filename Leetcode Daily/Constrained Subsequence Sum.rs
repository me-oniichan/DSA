use std::collections::BinaryHeap;

impl Solution {
    pub fn constrained_subset_sum(mut nums: Vec<i32>, k: i32) -> i32 {
        let mut pq: BinaryHeap<(i32, usize)>  = BinaryHeap::new();
        let k = k as usize;
        let mut ans = i32::MIN;

        for (i, v) in nums.iter_mut().enumerate(){
            while let Some(&x) = pq.peek(){
                if x.1+k < i{
                    pq.pop();
                }
                else {
                    let elem = *v+x.0;
                    *v = (*v).max(elem);
                    break;
                }
            }
            ans = ans.max(*v);    
            pq.push((*v, i));
        }

        ans
    }
}
