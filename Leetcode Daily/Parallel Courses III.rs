use std::collections::{VecDeque, HashSet};

impl Solution {
    pub fn minimum_time(n: i32, relations: Vec<Vec<i32>>, time: Vec<i32>) -> i32 {
        let mut finishtime = time.clone();

        let n = n as usize;
        let mut graph = vec![Vec::new();n];
        let mut indeg = vec![HashSet::new();n];
        for v in relations{
            graph[v[0] as usize -1].push(v[1] as usize -1); //outgoing edges
            indeg[v[1] as usize -1].insert(v[0] as usize-1); //incoming edges
        }
                
        let mut queue = VecDeque::new();
        
        for (i,j) in indeg.iter().enumerate(){
            if j.len() ==0{
                queue.push_back(i);
            }
        }

        while !queue.is_empty(){
            let node = queue.pop_front().unwrap();

            for &i in graph[node].iter(){
                let ftime = time[i]+finishtime[node];
                finishtime[i] = finishtime[i].max(ftime);
                indeg[i].remove(&node);
                if indeg[i].len() == 0{
                    queue.push_back(i);
                }
            }

        }

        *finishtime.iter().max().unwrap()

    }
}
