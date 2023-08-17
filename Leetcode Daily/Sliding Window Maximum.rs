use std::{cmp::Ordering, collections::VecDeque};

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut window = VecDeque::new();
        let k = k as usize;
        
        for i in 0..k{
            while !window.is_empty() && nums[*window.back().unwrap()] <= nums[i]{
                window.pop_back();
            }
            window.push_back(i)
        }

        let mut ans = Vec::new();
        ans.push(nums[*window.front().unwrap()]);
        for i in k..nums.len(){
            if !window.is_empty() && *window.front().unwrap() < i-k+1{
                window.pop_front();
            }

            while !window.is_empty() && nums[*window.back().unwrap()] <= nums[i]{
                window.pop_back();
            };

            window.push_back(i);

            ans.push(nums[*window.front().unwrap()]);

        }

        ans

    }
}
