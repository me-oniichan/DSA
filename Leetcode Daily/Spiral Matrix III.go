func spiralMatrixIII(rows int, cols int, rStart int, cStart int) [][]int {
	res := make([][]int, 0)
	res = append(res, []int{rStart, cStart})
	step := 1
	for len(res) < rows*cols {
		for i := 0; i < step; i++ {
			cStart++
			if rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols {
				res = append(res, []int{rStart, cStart})
			}
		}
		for i := 0; i < step; i++ {
			rStart++
			if rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols {
				res = append(res, []int{rStart, cStart})
			}
		}
		step++
		for i := 0; i < step; i++ {
			cStart--
			if rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols {
				res = append(res, []int{rStart, cStart})
			}
		}
		for i := 0; i < step; i++ {
			rStart--
			if rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols {
				res = append(res, []int{rStart, cStart})
			}
		}
		step++
	}
	return res
}
