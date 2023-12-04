impl Solution {
    pub fn largest_good_integer(num: String) -> String {
        let mut ans = "";
        let size = num.len();
        for i in 0..size-2{
            let sub = num.get(i..i+3).unwrap();
            if sub[..1_usize]==sub[1_usize..2_usize] && sub[1_usize..2_usize]==sub[2_usize..3_usize]{
                ans = ans.max(sub);
            }
        }

        ans.to_string()
        
    }
}
