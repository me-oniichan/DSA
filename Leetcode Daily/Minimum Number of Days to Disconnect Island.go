var dx = []int{1, -1, 0, 0}
var dy = []int{0, 0, 1, -1}

func fill(g [][]int, x, y int) {
	g[x][y] = 2
	for i := 0; i < 4; i++ {
		nx, ny := x+dx[i], y+dy[i]
		if nx < 0 || nx >= len(g) || ny < 0 || ny >= len(g[0]) || g[nx][ny] != 1 {
			continue
		}
		fill(g, nx, ny)
	}
}

func cnt(g [][]int) int {
	r := 0
	for i := 0; i < len(g); i++ {
		for j := 0; j < len(g[0]); j++ {
			if g[i][j] == 1 {
				r++
				fill(g, i, j)
			}
		}
	}

	for i := 0; i < len(g); i++ {
		for j := 0; j < len(g[0]); j++ {
			if g[i][j] == 2 {
				g[i][j] = 1
			}
		}
	}

	return r
}

func minDays(g [][]int) int {
	n, m := len(g), len(g[0])
	c := cnt(g)
	if c != 1 {
		return 0
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if g[i][j] == 1 {
				g[i][j] = 0
				c = cnt(g)
				if c != 1 {
					return 1
				}
				g[i][j] = 1
			}
		}
	}

	return 2
}
