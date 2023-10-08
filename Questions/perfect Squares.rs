impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let mut sq= Vec::new();
        for i in 1..(n as f64).sqrt() as i32+1{
            sq.push(i*i);
        }

        let n = n as usize;
        let mut dp = vec![i32::MAX; n+1];
        dp[1]=1;

        for i in 1..n+1{
            for &s in sq.iter(){
                if s > i{
                    break;
                }
                dp[i] = dp[i].min(dp[i-s]+1);
            }           
        }

        dp[n]
    }
}
