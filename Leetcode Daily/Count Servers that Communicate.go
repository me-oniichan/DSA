func countServers(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    row := make([]int, m)
    col := make([]int, n)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 1 {
                row[i]++
                col[j]++
            }
        }
    }
    res := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 1 && (row[i] > 1 || col[j] > 1) {
                res++
            }
        }
    }
    return res
}
