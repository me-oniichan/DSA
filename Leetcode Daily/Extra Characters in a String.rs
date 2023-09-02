use std::collections::{HashSet, hash_set};

impl Solution {
    pub fn min_extra_char(s: String, dictionary: Vec<String>) -> i32 {
        let mut dictionary: HashSet<String> = dictionary.into_iter().collect();
        let size = s.len();
        let mut dp = vec![size as i32; size+1];
        dp[0]=0; 
        for i in 1..size+1{
            for j in 0..i{
                let substr: String = s.get(j..i).unwrap().chars().collect();
                if dictionary.contains(&substr) {
                   dp[i] = dp[j].min(dp[i]); 
                }
            }
            dp[i]= dp[i].min(dp[i-1]+1);
        }

        dp[size]
    }
}
