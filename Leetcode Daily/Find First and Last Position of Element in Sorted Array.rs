impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        if nums.is_empty(){
            return vec![-1,-1];
        }
        let mut left = 0 as usize;
        let mut right = nums.len() -1;
        
        while left < right{
            let mid = (left+right)/2;
            if nums[mid] >= target{
                right=mid;
            }
           else {
                left = mid+1;                
            }
        }

        if nums[left]!=target{
            return vec![-1,-1];
        }
        
        let mut ans = vec![left as i32, 0];
        left=0;
        right = nums.len()-1;

        while left < right {
            let mid = (left+right+1)/2;
            if nums[mid]<=target{
                left = mid;
            }
            else {
                right=mid-1;
            }
        }

        ans[1] = right as i32;
        ans

    }
}










































