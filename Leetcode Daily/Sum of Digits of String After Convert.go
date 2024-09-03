func getLucky(s string, k int) int {
    var sum int
    tempstr := ""
    for _, c := range s {
        tempstr += strconv.Itoa(int(c) - 96)
    }
    
    for _, c := range tempstr {
        sum += int(c - '0')
    }

    for i := 2; i <= k; i++ {
        sum = sumOfDigits(sum)
    }
    return sum
}

func sumOfDigits(n int) int {
    sum := 0
    for n > 0 {
        sum += n % 10
        n /= 10
    }
    return sum
}
