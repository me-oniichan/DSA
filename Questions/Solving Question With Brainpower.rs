impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let size = questions.len();
        let mut dp = vec![0_i64; size];
        dp[size-1] = questions[size-1][0] as i64;
        for i in (0..size-1).rev(){
            let next = questions[i][1]+i as i32+1;
            let next = next as usize;
            dp[i] = questions[i][0] as i64 + match next >= size {
                true => 0_i64,
                false => dp[next],
            };

            dp[i] = dp[i].max(dp[i+1]);
        }

        dp[0]
    }
}

