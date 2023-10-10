use std::{cmp::Ordering, collections::{HashMap, HashSet, BTreeSet}};

impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        
        let size = nums.len();
        let uns: BTreeSet<i32>= nums.into_iter().collect();

        let mut nums: Vec<i32> = uns.into_iter().collect();
        
        let wsize = size as i32 -1;
        let mut ans=size;

        for i in 0..nums.len(){
            let find = nums[i]+wsize;
            let (Err(idx)| Ok(idx)) = nums.binary_search_by(|&x| match x.cmp(&find){
                Ordering::Equal => Ordering::Less,
                ord => ord,
            });
            
            let count = idx-i;
            ans = ans.min(size - count);
        }

        ans as i32
    }
}

