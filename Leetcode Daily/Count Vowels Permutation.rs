static M: i32 = 1e9 as i32 +7;

impl Solution {
    pub fn count_vowel_permutation(n: i32) -> i32 {
        let n = n as usize;
        let mut dp = vec![vec![0;5]; n];
        //let mut str = vec![' '; n];

        for i in 0..5 as usize{
            dp[n-1][i] = 1;
        }

        for i in (0..n-1).rev(){
            for j in 0..5 as usize{
                dp[i][j] += match j {
                    0 => dp[i+1][1],
                    1 => (dp[i+1][0] + dp[i+1][2])%M,
                    2 => (((dp[i+1][0] + dp[i+1][1])%M + dp[i+1][3])%M + dp[i+1][4])%M,
                    3 => (dp[i+1][2] + dp[i+1][4])%M,
                    4 => dp[i+1][0],
                    _ => 0,
                };
                dp[i][j] = dp[i][j]%M;
            }
        }

        let mut sum = 0;
        for &i in dp[0].iter(){
            sum = (i+sum)%M;
        }

        sum
    }
}

