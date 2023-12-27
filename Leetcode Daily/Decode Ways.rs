impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let n = s.len();

        let mut dp = vec![0; n + 1];
        dp[n] = 1;

        for i in (0..n).rev() {
            for j in (i..n) {
                let number: i32 = (&s[i..j + 1]).parse::<i32>().unwrap();
                if number >= 1 && number <= 26 {
                    dp[i] += dp[j + 1];
                } else {
                    break;
                }
            }
        }

        dp[0] as i32
    }
}
