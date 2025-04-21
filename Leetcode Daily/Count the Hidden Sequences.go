func numberOfArrays(differences []int, lower int, upper int) int {
    mn, mx := 0, 0
    sum := 0
    for _, diff := range differences {
        sum += diff
        if sum < mn {
            mn = sum
        }
        if sum > mx {
            mx = sum
        }
    }
    return  max((upper - lower + 1) - (mx - mn), 0)
}
