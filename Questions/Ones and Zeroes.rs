impl Solution {
    pub fn find_max_form(strs: Vec<String>, m: i32, n: i32) -> i32 {
        let size = strs.len();
        let (m,n) = (m as usize, n as usize);

        let mut srr= vec![(0_usize,0_usize); size];
        
        for (i, s) in strs.iter().enumerate(){
            let z = s.chars().filter(|&c| c=='0').count();
            srr[i] = (z, s.len()-z);
        }

        let mut dp = vec![vec![vec![0;n+1];m+1]; size+1];

        for i in (0..size).rev(){
            for j in (0..m+1).rev(){
                for k in (0..n+1).rev(){
                    dp[i][j][k] = dp[i+1][j][k];
                    
                    if j >= srr[i].0 && k>= srr[i].1{
                        dp[i][j][k] = dp[i][j][k].max(1+dp[i+1][j-srr[i].0][k-srr[i].1]);
                    }
                }
            }
        }

        dp[0][m][n]
    }
}

