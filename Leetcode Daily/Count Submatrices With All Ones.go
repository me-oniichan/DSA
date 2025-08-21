func numSubmat(mat [][]int) int {
	m, n := len(mat), len(mat[0])
	dp := make([][]int, m)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	
	mod := 1_000_000_007
	result := 0
	
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] == 1 {
				if j == 0 {
					dp[i][j] = 1
				} else {
					dp[i][j] = dp[i][j-1] + 1
				}
				count := dp[i][j]
				for k := i; k >= 0 && mat[k][j] == 1; k-- {
					count = min(count, dp[k][j])
					result = (result + count) % mod
				}
			}
		}
	}
	
	return result
}
