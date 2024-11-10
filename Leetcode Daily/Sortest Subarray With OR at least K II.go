func bits_to_num(bits []int) int {
    res := 0
    for i := 0; i < 32; i++ {
        if bits[i] != -1 {
            res |= 1<<i
        }
    }
    return res
}

func minimumSubarrayLength(nums []int, k int) int {
    n := len(nums)
    bits := make([]int, 32)
    for i := range bits {
        bits[i] = -1
    }

    res := n+1
    for l, r := 0, 0; r < n; r++ {
        for i := 0; i < 32; i++ {
            if nums[r] & (1<<i) > 0 {
                bits[i] = r
            }
        }

        num := bits_to_num(bits)
        for num >= k && l <= r{
            res = min(res, r-l+1)
            for i := 0; i < 32; i++ {
                if bits[i] == l {
                    bits[i] = -1
                }
            }
            l++
            num = bits_to_num(bits)
        }
    }
    if res == n+1 {
        return -1
    }
    return res
}
