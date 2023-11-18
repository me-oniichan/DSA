impl Solution {
    pub fn max_frequency(mut nums: Vec<i32>, mut k: i32) -> i32 {
        nums.sort_unstable();

        let mut left = 0_usize;
        let mut curheight = nums[left];
        let mut ans = 1;

        for right in 1..nums.len(){
            let mut req = (right-left) as i32*(nums[right]-curheight);

            while req > k{
                let free = curheight - nums[left];
                left+=1;
                k+=free;
                req-=nums[right]-curheight;
            }

            k-=req;
            curheight = nums[right];
            ans = ans.max(right - left+1);
        }

        ans as i32

    }
}

