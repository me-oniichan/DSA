impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let size = coins.len();
        let amount = amount as usize;
        let mut dp = vec![vec![0;size+1]; amount+1];

        for i in 0..size+1{
            dp[0][i] = 1;
        }

        for i in 1..size+1{
            for amt in 1..amount+1{
                let coin = coins[i-1] as usize;
                if(coin > amt){
                    dp[amt][i] = dp[amt][i-1];
                }
                else {
                    dp[amt][i] = dp[amt-coin][i]+dp[amt][i-1];
                }
            }
        }
        return dp[amount][size];
    }
}
