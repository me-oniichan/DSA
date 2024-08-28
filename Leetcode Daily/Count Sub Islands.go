func countSubIslands(grid1 [][]int, grid2 [][]int) int{
    m, n := len(grid1), len(grid1[0])
    var dfs func(i, j int) int
    dfs = func(i, j int) int {
        if i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0 {
            return 1
        }
        grid2[i][j] = 0
        res := grid1[i][j]
        for _, d := range [4][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} {
            res &= dfs(i+d[0], j+d[1])
        }
        return res
    }
    res := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid2[i][j] == 1 {
                res += dfs(i, j)
            }
        }
    }
    return res
}
