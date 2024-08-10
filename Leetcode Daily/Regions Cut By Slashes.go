func regionsBySlashes(grid []string) int {
	n := len(grid)
	m := 4 * n * n
	parent := make([]int, m)
	for i := 0; i < m; i++ {
		parent[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if parent[x] != x {
			parent[x] = find(parent[x])
		}
		return parent[x]
	}
	union := func(x, y int) {
		x, y = find(x), find(y)
		if x != y {
			parent[x] = y
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			base := 4 * (i*n + j)
			if grid[i][j] == '/' {
				union(base, base+3)
				union(base+1, base+2)
			} else if grid[i][j] == '\\' {
				union(base, base+1)
				union(base+2, base+3)
			} else {
				union(base, base+1)
				union(base+1, base+2)
				union(base+2, base+3)
			}
			if i > 0 {
				union(base, base-4*n+2)
			}
			if i < n-1 {
				union(base+2, base+4*n)
			}
			if j > 0 {
				union(base+3, base-3)
			}
			if j < n-1 {
				union(base+1, base+7)
			}
		}
	}
	ans := 0
	for i := 0; i < m; i++ {
		if find(i) == i {
			ans++
		}
	}
	return ans
}
