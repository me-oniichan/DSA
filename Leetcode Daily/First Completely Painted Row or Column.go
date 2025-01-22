func firstCompleteIndex(arr []int, mat [][]int) int {
	m, n := len(mat), len(mat[0])
	
	fullyPaintedRow := make([]int, m)
	fullyPaintedCol := make([]int, n)
	mapFlat := make(map[int]int)

	for i, row := range mat {
		for j, col := range row {
			mapFlat[col] = i*len(row) + j
		}
	}

	for i, paint := range arr {
		index := mapFlat[paint]
		row := index / n
		col := index % n

		fullyPaintedRow[row]++
		if fullyPaintedRow[row] == n {
			return i
		}

		fullyPaintedCol[col]++
		if fullyPaintedCol[col] == m {
			return i
		}
	}

	return 0
}
