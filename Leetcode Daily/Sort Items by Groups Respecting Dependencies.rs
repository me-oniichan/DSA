use std::collections::HashMap;
impl Solution {
    pub fn sort_items(
        n: i32,
        m: i32,
        mut group: Vec<i32>,
        before_items: Vec<Vec<i32>>,
    ) -> Vec<i32> {
        let mut group_id = m;
        group.iter_mut().filter(|g| **g == -1).for_each(|g| {
            *g = group_id;
            group_id += 1;
        });

        let mut item_graph: Vec<Vec<i32>> = vec![vec![]; n as _];
        let mut item_indegree = vec![0; n as _];

        let mut group_graph: Vec<Vec<i32>> = vec![vec![]; group_id as _];
        let mut group_indegree = vec![0; group_id as _];

        for curr in 0..n as usize {
            for prev in &before_items[curr] {
                let prev = *prev as usize;

                item_graph[prev].push(curr as i32);
                item_indegree[curr] += 1;

                if group[curr] != group[prev] {
                    let (ugp, ugc) = (group[prev] as usize, group[curr] as usize);

                    group_graph[ugp].push(group[curr]);
                    group_indegree[ugc] += 1;
                }
            }
        }

        let topo_sort = |graph: &mut Vec<Vec<i32>>, indegree: &mut Vec<i32>| -> Vec<i32> {
            let mut visited = vec![];
            let mut stack: Vec<i32> = (0..graph.len())
                .filter_map(|n| (indegree[n] == 0).then(|| n as i32))
                .collect();

            while let Some(curr) = stack.pop() {
                let uc = curr as usize;
                visited.push(curr);

                for nbr in &graph[uc] {
                    let nbr = *nbr as usize;
                    indegree[nbr] -= 1;

                    if indegree[nbr] == 0 {
                        stack.push(nbr as i32);
                    }
                }
            }

            match visited.len() == graph.len() {
                true  => visited,
                false => vec![],
            }
        };

        let item_order = topo_sort(&mut item_graph, &mut item_indegree);
        let group_order = topo_sort(&mut group_graph, &mut group_indegree);

        if item_order.is_empty() || group_order.is_empty() {
            return vec![];
        }

        let mut ordered_groups: HashMap<i32, Vec<i32>> = HashMap::new();
        for item in item_order {
            ordered_groups
                .entry(group[item as usize])
                .and_modify(|v| v.push(item))
                .or_insert(vec![item]);
        }

        group_order
            .into_iter()
            .flat_map(|v| match ordered_groups.remove(&v) {
                Some(arr) => arr,
                None      => vec![],
            })
            .collect()
    }
}
