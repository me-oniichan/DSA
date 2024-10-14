
type Item struct {
    value int
    row int
    col int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int {
    return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
    return pq[i].value < pq[j].value
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
    item := x.(*Item)
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
    n := len(*pq)
    item := (*pq)[n-1]
    *pq = (*pq)[:n-1]
    return item
}

func Max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func smallestRange(nums [][]int) []int {
    pq := make(PriorityQueue, 0)
    max := math.MinInt32
    for i := 0; i < len(nums); i++ {
        pq = append(pq, &Item{
            value: nums[i][0],
            row: i,
            col: 0,
        })
        max = Max(max, nums[i][0])
    }
    heap.Init(&pq)
    res := []int{pq[0].value, max}
    for {
        item := heap.Pop(&pq).(*Item)
        if item.col == len(nums[item.row]) - 1 {
            break
        }
        heap.Push(&pq, &Item{
            value: nums[item.row][item.col+1],
            row: item.row,
            col: item.col+1,
        })
        max = Max(max, nums[item.row][item.col+1])
        if max - pq[0].value < res[1] - res[0] {
            res[0], res[1] = pq[0].value, max
        }
    }
    return res
}
