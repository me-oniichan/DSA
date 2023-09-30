impl Solution {
    pub fn find132pattern(nums: Vec<i32>) -> bool {
        let size = nums.len();
        let mut mins = vec![i32::MAX;size];
        for i in 1..size{
            mins[i] = mins[i-1].min(nums[i-1]);
        }
        
        let mut k = Vec::new();
        for i in (0..size).rev(){
            if (nums[i] <= mins[i]){
                continue;
            }
            
            while !k.is_empty() {
               let n = k.last().unwrap();
               if (n <= &mins[i]){
                   k.pop();
               }
               else {
                   break;
               }
            }

            if !k.is_empty()&& k.last().unwrap() < &nums[i]{
                return true;
            }

            k.push(nums[i]);
        }

        false
    }
}
