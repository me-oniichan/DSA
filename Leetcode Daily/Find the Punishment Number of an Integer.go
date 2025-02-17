var num []int
func init() {
    for i := 1; i <= 1000; i++ {
        if check(i * i, 0, i) {
            num = append(num, i)
        }
    }
}

func check(num int, sum int, target int) bool {
    if num == 0 && sum == target {
        return true
    }
    size := 0
    copy := num
    for copy > 0 {
        copy /= 10
        size++
        p := pow(10, size)
        if check((num / p), sum + num % p, target) {
            return true
        }
    }
    return false
}

func pow(num int, n int) (re int) {
    re = 1
    for i := 0; i < n; i++ {
        re *= num
    }
    return
}

func punishmentNumber(n int) int {
    ans := 0
    for i := range num {
        if num[i] > n {
            break
        }
        ans += num[i] * num[i]
    }
    return ans
}
 
}

fstr string) bool {
 
}
