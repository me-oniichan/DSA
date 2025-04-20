func minOperations(nums []int, k int) int {
	for _, num := range nums {
		if num < k {
			return -1
		}
	}

	distinct_greater := make(map[int]bool)
	for _, num := range nums {
		if num > k {
			distinct_greater[num] = true
		}
	}

	return len(distinct_greater)
}
