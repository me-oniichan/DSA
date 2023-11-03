use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn find_shortest_cycle(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();

        edges.into_iter().for_each(|edge|{
            graph.entry(edge[0]).and_modify(|v| v.push(edge[1])).or_insert(vec![edge[1]]);
            graph.entry(edge[1]).and_modify(|v| v.push(edge[0])).or_insert(vec![edge[0]]);
        });

        let mut ans = 10001;
        for &v in graph.keys(){
            
            let mut q = VecDeque::new();
            q.push_back((v,-1));
            
            let mut visited = HashMap::new();
            visited.insert(v, 0);

            while !q.is_empty(){
                let (elem, parent) = q.pop_front().unwrap();
                let length = *visited.get(&elem).unwrap();
                for i in graph.get(&elem).unwrap(){
                    if *i == parent{
                        continue;
                    }
                    if let Some(&x) = visited.get(i){
                        ans = ans.min(x+length+1);
                        // q.clear();
                        break;
                    }
                    else {
                        q.push_back((*i, elem));
                        visited.insert(*i, length+1);
                    }
                }
            }

        }
        
        match ans {
            10001 => -1,
            x => x
        }
        
    }
}

