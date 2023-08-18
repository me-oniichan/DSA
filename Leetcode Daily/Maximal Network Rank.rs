use std::collections::HashSet;

impl Solution {
    pub fn maximal_network_rank(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut graph = vec![HashSet::new(); n];

        for pair in &roads{
            graph[pair[0] as usize].insert(pair[1]);
            graph[pair[1] as usize].insert(pair[0]);
        }
        let mut maxNetwork =0;
        for i in 0..n{
            for j in i+1..n{
                let networks = graph[i].len()+ graph[j].len();
                let mut networks = networks as i32;

                if graph[i].contains(&(j as i32)){
                    networks-=1;
                };
                maxNetwork = maxNetwork.max(networks);

            }
        }

        maxNetwork


    }
}
