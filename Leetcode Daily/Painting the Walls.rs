impl Solution {
    pub fn paint_walls(cost: Vec<i32>, time: Vec<i32>) -> i32 {
        let size = cost.len();
        let mut dp = vec![vec![0; size+1];size+1];
        
        for i in dp[0].iter_mut(){
            *i = 1e9 as i32;
        }
        dp[0][0] = 0;
        for i in 1..size+1{
            for r in 1..size+1{
                dp[i][r] = cost[i-1] + dp[i-1][0.max(r as i32-1-time[i-1]) as usize];
                dp[i][r] = dp[i][r].min(dp[i-1][r]);
            }
        }

        dp[size][size]
    }
}

