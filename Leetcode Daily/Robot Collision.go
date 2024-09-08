func survivedRobotsHealths(positions []int, healths []int, directions string) []int{
    
    choosedir := func(dir byte) int{
        if dir == 'R'{
            return 1
        }

        return 0
    }

    n := len(positions)
    robos := make ([][]int, n)
    for i:= 0; i < n; i++{
        robot := []int{positions[i], healths[i], choosedir(directions[i]) , i}
        robos[i] = robot
    }
    
    slices.SortFunc(robos, func(a, b []int) int {
        if a[0] < b[0]{
            return -1
        }else if a[0] == b[0]{
            return 0
        }
        return 1
    })
    
    stack := make([][]int, 0)
    for _, robo:= range robos{
        if len(stack) ==0{
            stack = append(stack, []int{robo[1], robo[2], robo[3]})
        }else if stack[len(stack)-1][1] == robo[2] || robo[2] == 1{
            stack = append(stack, []int{robo[1], robo[2], robo[3]})
        }else{
            for {
                if len(stack) <= 0 || stack[len(stack)-1][1] == 0{
                    if robo[1]>0{
                        stack = append(stack, []int{robo[1], robo[2], robo[3]})
                    }
                    break
                }

                top:= stack[len(stack)-1]
                if top[0] < robo[1]{
                    robo[1]--
                    stack = stack[:len(stack)-1]
                }else if top[0] == robo[1]{
                    stack = stack[:len(stack)-1]
                    break
                }else{
                    stack[len(stack)-1][0]--
                    break
                }
                
            }
        }
    }

    slices.SortFunc(stack, func(a, b []int) int {
        if a[2] < b[2]{
            return -1
        }else if a[2] == b[2]{
            return 0
        }
        return 1
    })
    

    ans := make([]int, len(stack))
    for i, s := range stack{
        ans[i] = s[0]
    }

    return ans
}
