func pivotArray(nums []int, pivot int) []int {
	lessEnd := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] < pivot {
			temp := nums[i]
			copy(nums[lessEnd+1:i+1], nums[lessEnd:i])
			nums[lessEnd] = temp
			lessEnd++
		}
	}
	for i := lessEnd; i < len(nums); i++ {
		if nums[i] == pivot {
			temp := nums[i]
			copy(nums[lessEnd+1:i+1], nums[lessEnd:i])
			nums[lessEnd] = temp
			lessEnd++
		}
	}
	return nums
}
