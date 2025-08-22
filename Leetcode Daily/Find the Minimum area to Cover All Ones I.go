func minimumArea(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	minRow, maxRow := m, -1
	minCol, maxCol := n, -1

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				if i < minRow {
					minRow = i
				}
				if i > maxRow {
					maxRow = i
				}
				if j < minCol {
					minCol = j
				}
				if j > maxCol {
					maxCol = j
				}
			}
		}
	}

	if maxRow == -1 {
		return 0 
	}

	return (maxRow - minRow + 1) * (maxCol - minCol + 1)
}
