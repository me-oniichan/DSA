type Element struct {
    endInterval int
    groupIndex int
}

func comparator(a, b interface{}) int {
    pa := a.(Element).endInterval
    pb := b.(Element).endInterval
    return pa - pb
}

func minGroups(intervals [][]int) int {
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i][0] < intervals[j][0]
    })

    groups := make([]int, 1)
    groups[0] = intervals[0][1]
    priority := priorityqueue.NewWith(comparator)
    priority.Enqueue(Element{endInterval: intervals[0][1], groupIndex: 0})

    for _, interval := range intervals[1:] {
        possibleGroup, _ := priority.Peek()
        // fmt.Println(priority.Values())
        if interval[0] > possibleGroup.(Element).endInterval {
            priority.Dequeue()
            groups[possibleGroup.(Element).groupIndex] = interval[1]
            priority.Enqueue(Element{endInterval: interval[1], groupIndex: possibleGroup.(Element).groupIndex})
        } else {
            groups = append(groups, interval[1])
            priority.Enqueue(Element{endInterval: interval[1], groupIndex: len(groups) - 1})
        }
    }

    return len(groups)
}
