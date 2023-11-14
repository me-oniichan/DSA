use std::collections::HashSet;

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let a = b'a' as usize;
        let s = s.as_bytes();
        let size = s.len();
        let mut ending = vec![-1; 26];
        let mut start = vec![-1; 26];

        for (i, &c) in s.iter().enumerate(){
            if start[c as usize - a] == -1{
                start[c as usize -a] = i as i32;
            }

            ending[c as usize -a] = i as i32;
        }

        let mut ans = 0;

        for i in 0..26 as usize{
            let mut unique: HashSet<u8> = HashSet::new();

            for j in start[i]+1..ending[i]{
                unique.insert(s[j as usize]);
            }

            ans+= unique.len();
        }

        ans as i32
    }
}

