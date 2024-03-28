impl Solution {
    pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut map = std::collections::HashMap::new();
        let mut ans = 0;
        let mut left = 0;

        for i in 0..nums.len(){
            map.entry(nums[i]).and_modify(|e| *e += 1).or_insert(1);
            
            while let Some(x) = map.get(&nums[i]){
                if left >= i{
                    break;
                }
                if *x > k{
                    map.entry(nums[left]).and_modify(|e| *e -= 1);
                    left += 1;
                }else{
                    break;
                }
            }
            ans = ans.max(i - left + 1);
        }
        ans as i32
    }
}
