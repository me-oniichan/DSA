func setZeroes(matrix [][]int)  {
	m, n := len(matrix), len(matrix[0])
	rowZero, colZero := false, false
	for i := 0; i < m; i++ {
		if matrix[i][0] == 0 {
			colZero = true
		}
	}
	for j := 0; j < n; j++ {
		if matrix[0][j] == 0 {
			rowZero = true
		}
	}

	for i:=1; i < m; i++{
		for j:= 1; j < n; j++{
			if matrix[i][j] == 0{
				matrix[0][j] = 0
				matrix[i][0] = 0
			}
		}
	}

	for i:=1; i < m; i++{
		if matrix[i][0] == 0 {
			for j := 0; j < n; j++ {
				matrix[i][j] = 0
			}
		}
	}
	for j:=1; j < n; j++{
		if matrix[0][j] == 0 {
			for i := 0; i < m; i++ {
				matrix[i][j] = 0
			}
		}
	}
	if rowZero {
		for j := 0; j < n; j++ {
			matrix[0][j] = 0
		}
	}
	if colZero {
		for i := 0; i < m; i++ {
			matrix[i][0] = 0
		}
	}
}
