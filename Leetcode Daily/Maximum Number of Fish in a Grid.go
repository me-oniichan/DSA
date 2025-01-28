func findMaxFish(grid [][]int) int {
    ans := 0
    direction := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

    for i:=0; i<len(grid); i++{
        for j:=0; j<len(grid[0]); j++{
            if grid[i][j] == 0{
                continue
            }
            q := [][]int{{i, j}}
            fish := 0
            for len(q) > 0{
                x, y := q[0][0], q[0][1]
                q = q[1:]
                if grid[x][y] == 0{
                    continue
                }
                fish += grid[x][y]
                grid[x][y] = 0
                for _, d := range direction{
                    nx, ny := x+d[0], y+d[1]
                    if nx >= 0 && nx < len(grid) && ny >= 0 && ny < len(grid[0]){
                        q = append(q, []int{nx, ny})
                    }
                }
            }
            ans = max(ans, fish)
        }
    }
    return ans
}
