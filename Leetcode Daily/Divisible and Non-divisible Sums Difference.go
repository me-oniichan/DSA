func differenceOfSums(n int, m int) int {
	num1 := (n*(n+1))/2
	mdivisibleSum := 0
	for i := m; i <= n; i += m {
		mdivisibleSum += i
	}
	num2 := (mdivisibleSum * 2)
	return num1 - num2
}
