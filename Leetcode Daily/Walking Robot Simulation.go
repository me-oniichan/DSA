func robotSim(commands []int, obstacles [][]int) int {
    dir := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    x, y, d, res := 0, 0, 0, 0
    obs := make(map[[2]int]bool)
    for _, o := range obstacles {
        obs[[2]int{o[0], o[1]}] = true
    }
    for _, c := range commands {
        if c == -2 {
            d = (d + 3) % 4
        } else if c == -1 {
            d = (d + 1) % 4
        } else {
            for i := 0; i < c; i++ {
                nx, ny := x + dir[d][0], y + dir[d][1]
                if _, ok := obs[[2]int{nx, ny}]; ok {
                    break
                }
                x, y = nx, ny
                res = max(res, x * x + y * y)
            }
        }
    }
    return res
}
