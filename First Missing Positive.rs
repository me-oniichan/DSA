use std::{mem::swap, num};

impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let mut nums = nums;

        let size = nums.len();
        for i in 0..size{
            let mut idx = nums[i] as usize -1;
            while nums[i] > 0 && nums[i] <= size as i32 && nums[i] != nums[idx]{
                nums.swap(i, idx);
                idx = nums[i] as usize -1;
            }
        }

        for i in 0..size{
            if nums[i] as usize != i+1{
                return i as i32 +1;
            }
        }

        size as i32 + 1
    }
}
