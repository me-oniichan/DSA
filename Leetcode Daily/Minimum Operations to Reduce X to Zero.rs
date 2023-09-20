impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let sum: i32 = nums.iter().sum();
        let target = sum-x;
        if target < 0{
            return -1;
        }
        else if target == 0{
            return nums.len() as i32;
        }

        let mut ans = 0;
        let mut left: usize=0;
        let mut sum = 0;
        for right in 0..nums.len(){
            sum+= nums[right];

            while sum > target{
                sum-= nums[left];
                left+=1;
            }

            if (sum == target){
                ans = ans.max(right as i32 - left as i32 +1); 
            }
            
        }
        
        
        match ans{
            0 => -1,
            x => nums.len() as i32 - ans
        }
    }
}
