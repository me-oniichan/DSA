func minimizedMaximum(n int, quantities []int) int {
	return sort.Search(1e5, func(x int) bool {
		var cnt int
		x++
		for _, y := range quantities {
			cnt += (y-1)/x + 1
		}
		return cnt <= n
	})+1
}
