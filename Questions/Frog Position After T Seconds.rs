use std::{collections::{HashMap, VecDeque}, cmp::Ordering};

impl Solution {
    pub fn dfs(graph: &HashMap<i32, Vec<i32>>, p: i32, n: i32, t: &i32, d: i32, target: &i32) -> f64{
        if d.cmp(t) == Ordering::Greater{
            return 0_f64;
        }
        else if n.cmp(target) == Ordering::Equal{
            if d.cmp(t) == Ordering::Equal || graph.get(&n).unwrap().len()==1{
                return 1.0;
            }
            return 0.0;
        }
        
        let mut ans = 0_f64;
        if let Some(node) = graph.get(&n){
            let childs = node.len() as f64 -1_f64;
            for i in node{
                if p.cmp(i) == Ordering::Equal{
                    continue;
                }
                ans+= Solution::dfs(graph, n, *i, t, d+1, target);
            }
            
            ans*= match childs {
                0.0 => 0.0,
                x => 1_f64/x,
            }
            
        }

        ans
        
    }
    pub fn frog_position(n: i32, edges: Vec<Vec<i32>>, t: i32, target: i32) -> f64 {
        let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();

        for edge in edges{
            graph.entry(edge[0]).and_modify(|x| x.push(edge[1])).or_insert(vec![edge[1]]);
            graph.entry(edge[1]).and_modify(|x| x.push(edge[0])).or_insert(vec![edge[0]]);
        }
        
        graph.entry(1).and_modify(|x| x.push(-1)).or_insert(vec![-1]);
        Solution::dfs(&graph, -1, 1, &t, 0, &target)
    }
}


