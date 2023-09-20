impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        for i in 0..nums.len(){
            let idx = nums[i].abs() as usize;
            if(nums[idx] < 0){
                return idx as i32;
            }
            nums[idx] = - nums[idx];
        }
        0
    }
}
