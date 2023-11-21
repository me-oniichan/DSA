use std::collections::HashMap;
const M: i32 = 10e9 as i32 +7;
impl Solution {
    pub fn count_nice_pairs(nums: Vec<i32>) -> i32 {
        let mut map = HashMap::new();
        let mut ans = 0;
        for i in nums{
            let mut origin = i;
            let mut rev = 0;

            while origin != 0{
                rev*=10;
                rev+=(origin%10);
                origin/=10;
            }

            let req = i - rev;

            if let Some(x) = map.get_mut(&req){
                ans+=*x;
                ans%=M;
                *x+=1;
            }
            else {
                map.insert(req, 1);
            }
        }

        ans
    }
}
