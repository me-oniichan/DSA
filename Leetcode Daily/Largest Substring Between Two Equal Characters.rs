use std::collections::HashMap;

impl Solution {
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let mut ans=-1;
        let mut table = HashMap::new();
        for (i,c) in s.chars().enumerate(){
            if let Some(val) = table.get(&c){
                ans = ans.max(i as i32 -val-1);
            }
            else {
                table.insert(c, i as i32);
            }
        }
        
        ans
    }
}
