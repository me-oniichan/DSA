impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let n = n as usize;
        let mut dp = vec![vec![0; n+1]; n+1];
        
        for i in 1..n+1{
            dp[i][i] = 1;
        }

        for diff in 2..n+1{
            for start in 1..n-diff+2{
                let end = start+diff-1;
                for pivot in start..end+1{
                    let mut left = 1;
                    let mut right = 1;
                    if(pivot > start) {left = dp[start][pivot-1];}
                    if(pivot < end) {right = dp[pivot+1][end];}
                    dp[start][end] += left*right;
                }
            } 
        }
        dp[1][n]
    }
}
