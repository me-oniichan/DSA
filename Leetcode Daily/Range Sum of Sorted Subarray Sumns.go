func rangeSum(nums []int , n int, left int, right int) int {
    const mod = 1e9 + 7
    var sum int
    var res int
    var arr []int
    for i := 0; i < n; i++ {
        sum = 0
        for j := i; j < n; j++ {
            sum += nums[j]
            arr = append(arr, sum)
        }
    }
    sort.Ints(arr)
    for i := left - 1; i < right; i++ {
        res = (res + arr[i]) % mod
    }
    return res
}
