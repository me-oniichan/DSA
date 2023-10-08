impl Solution {
    pub fn decode_at_index(s: String, k: i32) -> String {
        let mut idx=1 as usize;
        let mut k = k as usize;
        let mut len= 1 as usize;
        let s: Vec<char> = s.chars().collect();

        while len<k {
            if !s[idx].is_digit(10){
                len+=1;
                idx+=1;
                continue;
            }

            while let Some(x) = s[idx].to_digit(10){
                let new_len = len*x as usize;
                
                if new_len > k{
                    k = new_len - k;
                    len = 1;
                    idx = 1;
                    break;
                }
                
                idx+=1;
                len = new_len;
            }
        }

        s[idx].to_string()

    }
}
