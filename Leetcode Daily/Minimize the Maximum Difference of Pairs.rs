impl Solution {
    pub fn valid(diff:i32, p:&i32, nums: &mut Vec<i32>)->bool{
        let mut index: usize = 0;
        let mut count=0;

        while index+1 < nums.len(){
            let d = nums[index+1] - nums[index];
            if d <= diff{
                count+=1;
                index+=1;
            }
            
            if count >= *p{
                return true;
            }
            index+=1;
        }
        return false;
    }
    pub fn minimize_max(nums: Vec<i32>, p: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        
        let size = nums.len();
        let mut left=0;
        let mut right=nums[size-1] - nums[0];
        
        while left < right{
            let mid = (left + right)/2;
            if Solution::valid(mid, &p, &nums){
                right = mid;
            }
            else {
                left=mid+1;
            }
        }
        return right;
    }
}
