use std::collections::{BTreeMap, HashMap, HashSet, VecDeque};

impl Solution {
    pub fn find_all_people(n: i32, meetings: Vec<Vec<i32>>, first_person: i32) -> Vec<i32> {
        let n = n as usize;
        let mut has_secret = vec![false; n];

        let mut graph: BTreeMap<i32, HashMap<i32, Vec<i32>>> = BTreeMap::new();

        for meeting in meetings {
            let (a, b, t) = (meeting[0], meeting[1], meeting[2]);
            graph.entry(t).or_default().entry(a).or_default().push(b);
            graph.entry(t).or_default().entry(b).or_default().push(a);
        }

        has_secret[0] = true;
        has_secret[first_person as usize] = true;

        for (time, people) in graph{
            let mut visited = HashSet::new();
            for (&person,_) in people.iter(){
                let mut q = VecDeque::new();
                q.push_back(person);

                if (!visited.contains(&person) && has_secret[person as usize]){
                    while !q.is_empty() {
                        let front = q.pop_front().unwrap();
                        for &neighbour in people.get(&front).unwrap_or(&vec![]){
                            if !visited.contains(&neighbour){
                                visited.insert(neighbour);
                                has_secret[neighbour as usize] = true;
                                q.push_back(neighbour);
                            }
                        } 
                    }
                }
            }
        }

        let mut ans = Vec::new();
        for (i, _) in has_secret.into_iter().enumerate().filter(|(_, &x)| x){
            ans.push(i as i32);
        }
        ans 
    }
}
