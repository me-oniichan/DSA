impl Solution {
    pub fn can_split_array(nums: Vec<i32>, m: i32) -> bool {
        let size = nums.len();
        if(size<=2){
            return true;
        }

        for i in 1..size{
            if nums[i-1]+nums[i] >= m {
                return true;
            }
        }
        false
    }
}
