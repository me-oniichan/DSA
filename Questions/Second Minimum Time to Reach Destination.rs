use std::collections::VecDeque;

impl Solution {
    pub fn second_minimum(n: i32, edges: Vec<Vec<i32>>, time: i32, change: i32) -> i32 {
        let n = n as usize;
        let mut graph = vec![Vec::new(); n+1];
            
        edges.into_iter().for_each(|edge|{
            graph[edge[0] as usize].push(edge[1] as usize);
            graph[edge[1] as usize].push(edge[0] as usize);
        });
        
        let mut curtime=0;
        let mut d1 = vec![-1; n+1];
        let mut d2 = vec![-1; n+1];
        d1[1] = 0;

        let mut q = VecDeque::new();
        q.push_back((1_usize, false));

        while let Some((v, f)) = q.pop_front(){
            let mut ctime = match f {
                true => d2[v],
                false => d1[v]
            };

            if (ctime/change)%2 == 1{
                ctime+= change - (ctime%change);
            }

            ctime+=time;

            for &i in graph[v].iter(){
                if d1[i] == -1{
                    q.push_back((i, false));
                    d1[i] = ctime;
                }
                else if d2[i] == -1{
                    if i == n{
                        return ctime;
                    }

                    d2[i] = ctime;
                    q.push_back((i, true));
                }
            }
        }

        -1
        
    }
}
