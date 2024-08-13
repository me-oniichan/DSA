func combinationSum2(candidates []int, target int) [][]int {
    var res [][]int
    var dfs func(int, int, []int)
    sort.Ints(candidates)
    dfs = func(target, start int, path []int) {
        if target == 0 {
            res = append(res, append([]int{}, path...))
            return
        }
        for i := start; i < len(candidates); i++ {
            if i > start && candidates[i] == candidates[i-1] {
                continue
            }
            if target < candidates[i] {
                break
            }
            dfs(target-candidates[i], i+1, append(path, candidates[i]))
        }
    }
    dfs(target, 0, []int{})
    return res
}
