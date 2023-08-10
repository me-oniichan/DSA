use std::vec;

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let s1 = text1.len();
        let s2 = text2.len();

        let mut dp = vec![vec![0 as i32;s2+1]; s1+1];
        
        for i in 1..s1+1{
            for j in 1..s2+1 {
                if text1.as_bytes()[i-1] == text2.as_bytes()[j-1]{
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = std::cmp::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        dp[s1][s2]
    }
}
