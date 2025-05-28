func maxTargetNodes(edges1 [][]int, edges2 [][]int, k int) []int {
	n := len(edges1) + 1
	m := len(edges2) + 1

	adj1 := make([][]int, n)
	for _, edge := range edges1 {
		adj1[edge[0]] = append(adj1[edge[0]], edge[1])
		adj1[edge[1]] = append(adj1[edge[1]], edge[0])
	}
	adj2 := make([][]int, m)
	for _, edge := range edges2 {
		adj2[edge[0]] = append(adj2[edge[0]], edge[1])
		adj2[edge[1]] = append(adj2[edge[1]], edge[0])
	}

	getDistances := func(startNode int, adj [][]int, numNodes int) []int {
		dist := make([]int, numNodes)
		infinity := numNodes + 1
		for i := range dist {
			dist[i] = infinity
		}
		
		if startNode >= numNodes || startNode < 0 { 
			return dist 
		}
		
		dist[startNode] = 0
		q := make([]int, 0, numNodes)
		q = append(q, startNode)
		head := 0
		for head < len(q) {
			u := q[head]
			head++
			for _, v_node := range adj[u] {
				if dist[v_node] == infinity {
					dist[v_node] = dist[u] + 1
					q = append(q, v_node)
				}
			}
		}
		return dist
	}

	nodesReachableInT2UpToLimit := make([][]int, m)
	for j := 0; j < m; j++ {
		nodesReachableInT2UpToLimit[j] = make([]int, m)
		dist_from_j_T2 := getDistances(j, adj2, m)

		countsByDist := make([]int, m)
		for _, d_val := range dist_from_j_T2 {
			if d_val < m {
				countsByDist[d_val]++
			}
		}
		currentCumulativeCount := 0
		for d_idx := 0; d_idx < m; d_idx++ {
			currentCumulativeCount += countsByDist[d_idx]
			nodesReachableInT2UpToLimit[j][d_idx] = currentCumulativeCount
		}
	}
    
	maxReachableT2 := make([]int, k)
	if k > 0 {
		for r_prime_budget_for_T2 := 0; r_prime_budget_for_T2 < k; r_prime_budget_for_T2++ {
			valForThisBudget := 0
			
			lookup_d_in_T2 := r_prime_budget_for_T2
			if lookup_d_in_T2 >= m {
				lookup_d_in_T2 = m - 1
			}
            
			for c2 := 0; c2 < m; c2++ {
				current_c2_reach := nodesReachableInT2UpToLimit[c2][lookup_d_in_T2]
				if current_c2_reach > valForThisBudget {
					valForThisBudget = current_c2_reach
				}
			}
			maxReachableT2[r_prime_budget_for_T2] = valForThisBudget
		}
	}

	answer := make([]int, n)
	for s := 0; s < n; s++ {
		dist1_from_s := getDistances(s, adj1, n)

		n1_s_k := 0
		for v_t1 := 0; v_t1 < n; v_t1++ {
			if dist1_from_s[v_t1] <= k {
				n1_s_k++
			}
		}

		maxTargetsFromT2ForS := 0
		if k > 0 {
			for c1 := 0; c1 < n; c1++ {
				d_s_c1 := dist1_from_s[c1]
				
				if d_s_c1 >= n { continue }

				r_prime_budget_for_T2 := k - 1 - d_s_c1

				if r_prime_budget_for_T2 >= 0 {
					current_T2_targets_contribution := maxReachableT2[r_prime_budget_for_T2]
					if current_T2_targets_contribution > maxTargetsFromT2ForS {
						maxTargetsFromT2ForS = current_T2_targets_contribution
					}
				}
			}
		}
		answer[s] = n1_s_k + maxTargetsFromT2ForS
	}

	return answer
}
