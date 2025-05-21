func isZeroArray(nums []int, queries [][]int) bool {
	n := len(nums)

	auxArr := make([]int, n)
	for _,q := range queries {
		auxArr[q[0]]++
		if q[1]+1 < n {
			auxArr[q[1]+1]--
		}
	}
	currSum := 0
	for i := 0; i < n; i++{
		currSum += auxArr[i]
		if currSum < nums[i] {
			return false
		}
	}

	return true
}
