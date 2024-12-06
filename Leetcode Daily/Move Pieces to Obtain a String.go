func canChange(start string, target string) bool {
    if len(start) != len(target) {
        return false
    }
    s1, s2 := 0, 0
    for ; s1 < len(start) || s2 < len(target); {
        if s1 < len(start) && start[s1] == '_'{
            s1++
        } else if s2 < len(target) && target[s2] == '_' {
            s2++
        } else if len(start) == s1 || len(target) == s2{
            return s1 == len(start) && s2 == len(target)
        } else if start[s1] != '_' && target[s2] != '_'{
            if start[s1] != target[s2] {
                return false
            } else if start[s1] == 'R' && s1 > s2 {
                return false
            } else if start[s1] == 'L' && s1 < s2 {
                return false
            }
            s1++
            s2++
        }
    }
    return s1 == len(start) && s2 == len(target)
}
