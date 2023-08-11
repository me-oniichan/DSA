impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let size = prices.len();
        let mut dp = vec![vec![0;size+1]; 2];
        
        dp[0][1] = -prices[0];

        for i in 2..size+1 {
            dp[0][i] = dp[0][i-1].max(dp[1][i-2] - prices[i-1]);
            dp[1][i] = dp[1][i-1].max(dp[0][i-1]+prices[i-1]);
        }

        return dp[1][size];
    }
}
