impl Solution {
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let target = target as usize;
        let mut dp = vec![0; target+1];
        dp[0] = 1;
        for i in 1..target+1{
            for &num in nums.iter(){
                if i as i32-num >= 0{
                    dp[i] += dp[i-num as usize];                    
                }
            }
        }

        dp[target]
    }
}
