use std::{collections::{BinaryHeap, HashSet, HashMap}, cmp::Reverse};

struct Graph {
    alist : Vec<Vec<(usize, i32)>>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Graph {

    fn new(n: i32, edges: Vec<Vec<i32>>) -> Self {
        let mut alist: Vec<Vec<(usize, i32)>> = vec![Vec::new(); n as usize];

        for edge in edges{
            alist[edge[0] as usize].push((edge[1] as usize, edge[2]));
        }

        Graph { alist }
    }
    
    fn add_edge(&mut self, edge: Vec<i32>) {
        self.alist[edge[0] as usize].push((edge[1] as usize, edge[2])); 
    }
    
    fn shortest_path(&mut self, node1: i32, node2: i32) -> i32 {
        let mut ans = 0;
        let mut pq: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::new();
        //let mut visited = HashSet::new();
        pq.push(Reverse((0, node1 as usize)));
        let mut costs = HashMap::new();
        costs.insert(node1 as usize, 0);

        let node2 = node2 as usize;

        while let Some(Reverse((wei, cur))) = pq.pop(){
            if wei > match costs.get(&cur){
                None => i32::MAX,
                Some(&x) => x
            }{
                continue;
            }
            else if cur == node2{
                return wei;
            }
            else {
                for &(edge, weight) in self.alist[cur].iter(){
                    let curcost = match costs.get(&edge){
                        None => i32::MAX,
                        Some(&x) => x
                    };

                    if curcost > wei+weight{
                        costs.entry(edge as usize).and_modify(|x| *x = wei+weight).or_insert(wei+weight);
                        pq.push(Reverse((wei+weight, edge)));
                    }

                }      
            }
        }
        -1
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * let obj = Graph::new(n, edges);
 * obj.add_edge(edge);
 * let ret_2: i32 = obj.shortest_path(node1, node2);
 */


