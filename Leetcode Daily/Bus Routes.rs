use std::collections::{HashMap, VecDeque, HashSet};

impl Solution {
    pub fn num_buses_to_destination(mut routes: Vec<Vec<i32>>, source: i32, target: i32) -> i32 {

        if source == target{
            return 0;
        }

        let mut graph: HashMap<i32, Vec<usize>> = HashMap::new();

        routes.iter().enumerate().for_each(|(bus, route)|{
            let size = route.len();

            route.iter().for_each(|(&stop)|{
                graph.entry(stop)
                    .and_modify(|x| x.push(bus))
                    .or_insert(vec![bus]);
                
            });
        }); 

        let mut q = VecDeque::new();
        let mut visited = HashSet::new();

        let mut count = 1;

        if let Some(route) = graph.get(&source){
            for &r in route{
                q.push_back(r);
                visited.insert(r);
            }
        }

        while !q.is_empty(){
            let size = q.len();

            for i in 0..size{
                let route = q.pop_front().unwrap();

                for stop in routes[route].iter(){
                    if stop == &target{
                        return count;
                    }

                    if let Some(next) = graph.get(stop){
                        for nroute in next{
                            if !visited.contains(nroute){
                                visited.insert(*nroute);
                                q.push_back(*nroute);
                            }
                        }
                    }
                }
            }

            count+=1;
        }
        
        -1

    }
}
