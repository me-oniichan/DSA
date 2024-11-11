func sieve(n int) []int {
    primes := make([]bool, n+1)
    for i := 2; i <= n; i++ {
        primes[i] = true
    }
    for i := 2; i*i <= n; i++ {
        if primes[i] {
            for j := i*i; j <= n; j += i {
                primes[j] = false
            }
        }
    }
    primenumbers := []int{}
    primenumbers = append(primenumbers, 0)
    for i := 2; i <= n; i++ {
        if primes[i] {
            primenumbers = append(primenumbers, i)
        }
    }
    return primenumbers
}

func getMax(arr []int) int {
    max := arr[0]
    for _, v := range arr {
        if v > max {
            max = v
        }
    }
    return max
}

func lowerbound(arr []int, target int) int {
    left, right := 0, len(arr)
    for left < right {
        mid := (left + right) / 2
        if arr[mid] < target {
            left = mid + 1
        } else {
            right = mid
        }
    }
    // fmt.Println(target, arr[left])
    if arr[left] <= target || arr[left]==0{
        return arr[left]
    }
    return arr[left-1]
}

func primeSubOperation(nums []int) bool {
    n := len(nums)
    maxmelem := getMax(nums)
    primes := sieve(maxmelem)
    primes = append(primes, maxmelem)
    // fmt.Println(primes)
    nums[0]-= lowerbound(primes, nums[0]-1) 

    for i := 1; i < n; i++ {
        diff:= nums[i]-nums[i-1]
        if diff <= 0 {
            // fmt.Print(nums)
            return false
        }
        nums[i]-= lowerbound(primes, diff-1)
    }
    // fmt.Print(nums)
    return true
}
