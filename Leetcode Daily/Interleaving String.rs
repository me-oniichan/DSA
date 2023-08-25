impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let size1 = s1.len();
        let size2 = s2.len();
        
        let s1 = s1.as_bytes();
        let s2 = s2.as_bytes();
        let s3 = s3.as_bytes();
        let mut dp = vec![vec![false; size2+1]; size1+1];
        dp[0][0] = true;

        for i in 0..size1{
            dp[i+1][0] = dp[i][0] & (s1[i] == s3[i]);
        }

        for i in 0..size2{
            dp[0][i+1] = dp[0][i] & (s2[i] == s3[i]);
        }

        for i in 0..size1{
            for j in 0..size2 {
                dp[i+1][j+1] = (dp[i+1][j] & s2[j] == s3[i+j+1]) | (dp[i][j+1] & s1[i]==s3[i+j+1])
            }
        }

        dp[size1][size2]

    }
}
