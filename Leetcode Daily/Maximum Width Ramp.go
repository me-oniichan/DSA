func maxWidthRamp(nums []int) int {
	n := len(nums)
	stack := []int{}
	for i := 0; i < n; i++ {
		if len(stack) == 0 || nums[stack[len(stack)-1]] > nums[i] {
			stack = append(stack, i)
		}
	}
	res := 0
	for i := n - 1; i >= 0; i-- {
		for len(stack) > 0 && nums[stack[len(stack)-1]] <= nums[i] {
			res = max(res, i-stack[len(stack)-1])
			stack = stack[:len(stack)-1]
		}
	}
	return res
}
