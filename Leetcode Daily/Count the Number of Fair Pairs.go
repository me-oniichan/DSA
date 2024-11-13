func binarySearchLower(nums []int, lower int, start int) int{
    left, right := start+1, len(nums)
    for left < right {
        mid := (left + right) / 2
        if nums[mid]+nums[start] < lower {
            left = mid + 1
        } else {
            right = mid
        }
    }
    if left>=len(nums) || nums[left]+nums[start] < lower{
        return -1
    }
    return left
}
func binarysearchUpper(nums []int, upper int, start int) int {
    left, right := start+1, len(nums)
    for left < right {
        mid := (left + right) / 2
        if nums[mid]+nums[start] > upper {
            right = mid
        } else {
            left = mid+1
        }
    }
    return left
}

func countFairPairs(nums []int, lower int, upper int) int64 {
    sort.Ints(nums)
    // fmt.Println(nums)
    n := len(nums)
    var ans int64

    for i := 0; i < n-1; i++ {
        left := binarySearchLower(nums, lower, i)
        right := binarysearchUpper(nums, upper, i)
        // fmt.Println(i, left, right)

        if left == -1 || right == -1{
            continue
        }
        if left <= right{
            ans += int64(right - left)
        }
    }
    return ans
}
