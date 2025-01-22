func highestPeak(isWater [][]int) [][]int {
    n, m := len(isWater), len(isWater[0])
    res := make([][]int, n)
    for i := range res {
        res[i] = make([]int, m)
        for j := range res[i] {
            res[i][j] = -1
        }
    }
    q := make([][2]int, 0)
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if isWater[i][j] == 1 {
                res[i][j] = 0
                q = append(q, [2]int{i, j})
            }
        }
    }
    for len(q) > 0 {
        i, j := q[0][0], q[0][1]
        q = q[1:]
        for _, d := range [][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}} {
            ni, nj := i+d[0], j+d[1]
            if ni >= 0 && ni < n && nj >= 0 && nj < m && res[ni][nj] == -1 {
                res[ni][nj] = res[i][j]+1
                q = append(q, [2]int{ni, nj})
            }
        }
    }
    return res
}
