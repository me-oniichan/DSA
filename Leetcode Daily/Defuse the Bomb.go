func decrypt(code []int, k int) []int {
    n := len(code)    
    res := make([]int, n)

    if k == 0 {
        return res
    }else if k > 0{
        windowsum := 0
        for i := 1; i <= k; i++ {
            windowsum += code[i]
        }

        res[0] = windowsum
        for i := 1; i < n; i++ {
            windowsum += code[(i+k)%n] - code[i]
            res[i] = windowsum
        }
    }else{
        windowsum := 0
        for i := n+k; i < n; i++ {
            windowsum += code[i]
        }

        res[0] = windowsum
        for i := 1; i < n; i++ {
            windowsum += code[i-1] - code[(i+k+n-1)%n]
            res[i] = windowsum
        }
    }

    return res
}
