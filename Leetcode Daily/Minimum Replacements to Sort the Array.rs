impl Solution {
    pub fn minimum_replacement(nums: Vec<i32>) -> i64 {
        let mut ans =0;
        let mut nums = nums;
        let mut prev = *nums.last().unwrap() as i64;
        nums.pop();
        let size = nums.len();
        
        while nums.len() > 0 {
            let number = *nums.last().unwrap() as i64;
            nums.pop();
            if prev < number{
                let count = (number+prev-1)/prev;

                ans+=count-1;
                prev = number/count;
            }
            else {
                prev = number;
            }
        }
        ans

    }
}
