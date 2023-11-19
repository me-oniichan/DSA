use std::{collections::{HashMap, BTreeSet}, cmp::Reverse};

impl Solution {
    pub fn reduction_operations(nums: Vec<i32>) -> i32 {
        let mut map = HashMap::new();
        let mut pq = BTreeSet::new();

        for i in nums{
            map.entry(i).and_modify(|x| *x += 1).or_insert(1);
            pq.insert(Reverse(i));
        }

        let mut ans = 0;
        let mut prev = 0;
        for Reverse(num) in pq{
            if let Some(count) = map.get_mut(&num){
                ans+=prev;
                *count+=prev;
                prev = *count;
            }
        }

        ans
    }
}
