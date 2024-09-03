func survivedRobotsHealths(positions []int, healths []int, directions string) []int{
	mixarr := make([][]int, len(positions))
	for i := 0; i < len(positions); i++ {
		mixarr[i] = []int{positions[i], healths[i], i}
	}
	sort.Slice(mixarr)

	stack := make([][]int, 0)
	for i := 0; i < len(mixarr); i++{
		if len(stack) == 0 || stack[len(stack)-1
		}
	}

}
