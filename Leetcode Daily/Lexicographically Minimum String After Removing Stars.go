type Item struct {
	B byte 
	I int  
}

type PriorityQueue []Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].B != pq[j].B {
		return pq[i].B < pq[j].B 
	}
	return pq[i].I > pq[j].I 
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[:n-1]
	return item
}

func clearStars(s string) string {
	pq := PriorityQueue{}
	hmap := make(map[int]bool)
	for i, c := range s{
		if c == '*' {
			if len(pq) > 0 {
				elem := heap.Pop(&pq).(Item)
				hmap[elem.I] = true
			}
		}else{
            heap.Push(&pq, Item{B: s[i], I: i})
        }
	}

	buff := make([]byte, 0)
    // fmt.Println(hmap)
	for i, c := range s{
		if c!='*' && !hmap[i] {
			buff = append(buff, s[i])
		}
	}
	return string(buff)
}
