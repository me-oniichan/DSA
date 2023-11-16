impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let mut ans = String::new();

        for i in 0..nums.len(){
            unsafe{
                ans.push( match nums[i].get_unchecked(i..i+1){
                    "0"=> '1',
                    "1" => '0',
                    _ => '-'
                });
            }
        }

        ans
    }
}
