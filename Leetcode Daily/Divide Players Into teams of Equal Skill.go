func dividePlayers(skill []int) int64 {
    sort.Ints(skill)
    n := len(skill)
    if n <= 2{
        return int64(skill[0]*skill[1])
    }
    teamskill := skill[0] + skill[n-1]
    chemistry := int64(skill[0]*skill[n-i-1])
    for i := 1; i < n/2; i++ {
        skills := skill[i] + skill[n-i-1]
        if skills != teamskill {
            return int64(-1)
        }
        chemistry += int64(skill[i]*skill[n-i-1])
    }
    return chemistry
}
