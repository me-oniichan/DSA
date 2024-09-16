func findMinDifference(timePoints []string) int {
    sort.Strings(timePoints)
    min := 24 * 60
    for i := 0; i < len(timePoints); i++ {
        t1 := strings.Split(timePoints[i], ":")
        h1, _ := strconv.Atoi(t1[0])
        m1, _ := strconv.Atoi(t1[1])
        t2 := strings.Split(timePoints[(i+1)%len(timePoints)], ":")
        h2, _ := strconv.Atoi(t2[0])
        m2, _ := strconv.Atoi(t2[1])
        diff := (h2 - h1) * 60 + m2 - m1
        if diff < 0 {
            diff += 24 * 60
        }
        if diff < min {
            min = diff
        }
    }
    return min
}
