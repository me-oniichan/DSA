func resultsArray(nums []int, k int) []int {
    n := len(nums)
    if k == 1 {
        return nums
    }
    res := make([]int, n-k+1)
    tfarrray := make([]bool, n)
    tfarrray[0] = false
    for i := 1; i < n; i++ {
        if nums[i] == nums[i-1]+1 {
            tfarrray[i] = true
        }else {
            tfarrray[i] = false
        }
    }
    // fmt.Println(tfarrray)
    tcount := 0
    for i := 0; i < k; i++ {
        if tfarrray[i] {
            tcount++
        }
    }

    if tcount == k-1{
        res[0] = nums[k-1]
    }else {
        res[0] = -1
    }

    for i := k; i < n; i++ {
        if tfarrray[i] {
            tcount++
        }
        if tfarrray[i-k+1] {
            tcount--
        }
        if tcount == k-1 {
            res[i-k+1] = nums[i]
        }else {
            res[i-k+1] = -1
        }
    }

    return res
}
