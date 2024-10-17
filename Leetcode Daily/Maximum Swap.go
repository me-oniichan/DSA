func maximumSwap(num int) int {
    s := strconv.Itoa(num)
    a := make([]int, len(s))
    for i := range s {
        a[i] = int(s[i] - '0')
    }
    b := make([]int, len(s))
    for i := range s {
        b[i] = a[i]
    }
    for i := 0; i < len(s); i++ {
        for j := i + 1; j < len(s); j++ {
            a[i], a[j] = a[j], a[i]
            if compare(a, b) > 0 {
                for k := range s {
                    b[k] = a[k]
                }
            }
            a[i], a[j] = a[j], a[i]
        }
    }
    res := 0
    for i := range s {
        res = res * 10 + b[i]
    }
    return res
}

func compare(a, b []int) int {
    for i := range a {
        if a[i] < b[i] {
            return -1
        } else if a[i] > b[i] {
            return 1
        }
    }
    return 0
}
