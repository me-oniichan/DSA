func gridGame(grid [][]int) int64 {
    m := len(grid[0])
    var top, but, maxS, minS int64
    minS = math.MaxInt64


    for i:=0; i<m; i++ {
        top = top+int64(grid[0][i])
    }


    for i:=0; i<m; i++ {
        top = top - int64(grid[0][i])
        maxS = max(top, but)
        minS = min(minS, maxS)
        but = but + int64(grid[1][i])
    }

    return minS
}
