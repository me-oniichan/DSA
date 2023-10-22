impl Solution {
    pub fn maximum_score(nums: Vec<i32>, k: i32) -> i32 {
        let (size, k) = (nums.len(), k as usize);
        let mut nums = nums;

        for i in (0..k).rev(){
            nums[i] = nums[i].min(nums[i+1]);
        }
        for i in k+1..size{
            nums[i] = nums[i].min(nums[i-1]);
        }

        let mut ans = nums[k];
        let mut left = k;
        let mut right = k;

        while left > 0 && right+1 < size{
            if nums[left-1] == nums[right+1]{
                left-=1;
                right+=1;
                ans = ans.max(nums[right]*((right-left) as i32 +1));
            }
            else if nums[left-1] < nums[right+1]{
                right+=1;
                ans = ans.max(nums[right]*((right-left) as i32 +1));
            }else {
                left-=1;
                ans = ans.max(nums[left]*((right-left) as i32 +1));
            }

        }
        
        for i in 0..left{
            ans = ans.max(nums[i]*((right - i) as i32 +1));
        }

        for i in right+1..size{
            ans = ans.max(nums[i]*((i-left) as i32 +1));
        }
        return ans;
    }
}

