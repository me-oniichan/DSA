impl Solution {
    pub fn max_score(s: String) -> i32 {
        let ones = s.chars().filter(|c| *c=='1').count();
        
        let mut o = 0_usize;
        let mut z = 0_usize;
        let mut ans = 0;
        for c in s.chars().take(s.len()-1){
            match c {
                '1' => {
                    o+=1;
                },
                '0' =>{
                    z+=1;
                },
                _ => {}
            }

            ans = ans.max(z+ones-o);
        }

        ans as i32
    }
}
