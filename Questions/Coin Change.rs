impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let size = coins.len();
        let amount = amount as usize;
        let mut dp = vec![1e9 as i32; amount+1];
        
        dp[0] = 0;

        for i in 1..amount+1{
            for &coin in coins.iter(){
                let req = match (i as i32 >= coin) {
                    false => 1e9 as i32,
                    true => 1+dp[i- coin as usize],
                };

                dp[i] = dp[i].min(req);

            } 
        }

        match dp[amount] >= 1e9 as i32{
            true => -1,
            false => dp[amount],
        }
    }
}
