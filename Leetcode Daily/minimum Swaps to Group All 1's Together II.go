func minSwaps(nums []int) int {
 arr := make([]int, 2*len(nums))
	k := 0
	for j := 0; j < 2; j++ {
		for i := 0; i < len(nums); i++ {
			arr[k] = nums[i]
			k++
		}
	}

	oneCount := 0
	for _, num := range nums {
		if num == 1 {
			oneCount++
		}
	}

	if oneCount == 0 {
		return 0
	}

	left, right, maxi, currentOne := 0, 0, math.MaxInt32, 0

	for right = 0; right < len(arr); right++ {
		if arr[right] == 1 {
			currentOne++
		}
		if right-left+1 == oneCount {
			maxi = min(oneCount-currentOne, maxi)
			if arr[left] == 1 {
				currentOne--
			}
			left++
		}
	}

	return maxi
}
