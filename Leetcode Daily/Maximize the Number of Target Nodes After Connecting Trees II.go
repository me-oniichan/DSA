func maxTargetNodes(edges1 [][]int, edges2 [][]int) []int {
	n1 := len(edges1)+1
	n2 := len(edges2)+1

	graph1 := make([][]int, n1)
	graph2 := make([][]int, n2)
	for _, edge := range edges1 {
		u, v := edge[0], edge[1]
		graph1[u] = append(graph1[u], v)
		graph1[v] = append(graph1[v], u)
	}
	for _, edge := range edges2 {
		u, v := edge[0], edge[1]
		graph2[u] = append(graph2[u], v)
		graph2[v] = append(graph2[v], u)
	}
	groupmap := make([]bool, n1)
	group1 := make([]int, 2)
	group2 := make([]int, 2)

	dfs1(0, graph1, -1, group1, false, groupmap)
	dfs2(0, graph2, -1, false, group2)
	maxm := max(group2[0], group2[1])

	answer := make([]int, n1)

	for i:=0; i < n1; i++{
		answer[i] = group1[btoi(groupmap[i])] + maxm
	}

	return answer
}

func dfs1(node int, graph [][]int, parent int, group []int, parity bool, groupmap []bool) {
	group[btoi(parity)]++
	groupmap[node] = parity

	for _, neighbor := range graph[node] {
		if neighbor == parent {
			continue
		}
		dfs1(neighbor, graph, node, group, !parity, groupmap)
	}
}

func dfs2(node int, graph [][]int, parent int, parity bool, group []int){
	group[btoi(parity)]++

	for _, neighbor := range graph[node]{
		if neighbor == parent{
			continue
		}
		dfs2(neighbor, graph, node, !parity, group)
	}
}

func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}
