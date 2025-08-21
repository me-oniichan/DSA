func maximumUniqueSubarray(nums []int) int {
	hmap := make(map[int]bool)
	window_sum := 0
	max_sum := 0
	left := 0
	for right := 0; right < len(nums); right++ {
		if exists, _ := hmap[nums[right]]; exists {
			for nums[left] != nums[right] {
				hmap[nums[left]] = false
				window_sum -= nums[left]
				left++
			}
            left++
		} else {
			hmap[nums[right]] = true
			window_sum += nums[right]
			max_sum = max(max_sum, window_sum)
		}
	}
	return max_sum
}
