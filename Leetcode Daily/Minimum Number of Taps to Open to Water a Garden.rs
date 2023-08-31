impl Solution {
    pub fn min_taps(n: i32, ranges: Vec<i32>) -> i32 {
        let n = n as usize;
        let inf = 1e9 as i32;
        let mut dp = vec![inf;n+1];
        dp[0] = 0;

        for (i, range) in ranges.iter().enumerate(){
            let start = 0.max(i as i32 -*range) as usize;
            let end = n.min(i+*range as usize);

            for j in start..end+1{
                dp[end] = dp[end].min(dp[j]+1);
            }
            
        }
        if dp[n] == inf{
            return -1;
        }
        dp[n]
    }
}
