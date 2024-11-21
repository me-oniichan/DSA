func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
    // Write your code here
    var grid = make([][]int, m)
    for i := 0; i < m; i++ {
        grid[i] = make([]int, n)
    }
    
    for i := 0; i < len(walls); i++ {
        grid[walls[i][0]][walls[i][1]] = -1
    }
    
    for i := 0; i < len(guards); i++ {
        grid[guards[i][0]][guards[i][1]] = 1
    }
    for i := 0; i < len(guards); i++ {
        x, y := guards[i][0], guards[i][1]
        for j := x+1; j < m; j++ {
            if grid[j][y] == -1 || grid[j][y] == 1 {
                break
            }
            grid[j][y] = 2
        }
        for j := x-1; j >= 0; j-- {
            if grid[j][y] == -1 || grid[j][y] == 1 {
                break
            }
            grid[j][y] = 2
        }
        for j := y+1; j < n; j++ {
            if grid[x][j] == -1 || grid[x][j] == 1 {
                break
            }
            grid[x][j] = 2
        }
        for j := y-1; j >= 0; j-- {
            if grid[x][j] == -1 || grid[x][j] == 1 {
                break
            }
            grid[x][j] = 2
        }
    }
    
    var count = 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 0 {
                count++
            }
        }
    }
    
    return count
}
