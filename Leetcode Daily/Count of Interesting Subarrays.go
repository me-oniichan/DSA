func countInterestingSubarrays(nums []int, modulo int, k int) int64 {
	n := len(nums)
	var result int64 = 0
	counts := make(map[int]int)
	counts[0] = 1
	prefixCnt := 0

	for i := 0; i < n; i++ {
		if nums[i]%modulo == k {
			prefixCnt++
		}
		currentMod := prefixCnt % modulo
		targetMod := (currentMod - k + modulo) % modulo

		if count, ok := counts[targetMod]; ok {
			result += int64(count)
		}
		counts[currentMod]++
	}
	return result
}
