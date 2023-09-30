use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn remove_duplicate_letters(s: String) -> String {
        let mut hmap = HashMap::new();
        let mut hset = HashSet::new(); 
        for (i,c) in s.chars().enumerate(){
            hmap.insert(c, i);
        }

        let mut st = Vec::new();
        st.push(s.chars().nth(0).unwrap());
        hset.insert(*st.last().unwrap());
        for (i,c) in s.chars().enumerate(){
            let top = st.last().unwrap();
            if hset.contains(&c){
                continue;
            }
            else if top < &c {
                hset.insert(c);
                st.push(c);
            }
            else {
                while !st.is_empty(){
                    let top = st.last().unwrap();
                    if top > &c && hmap.get(top).unwrap() > &i{
                        hset.remove(top);
                        st.pop();
                        continue;
                    }
                    break;
                }
                hset.insert(c);
                st.push(c);
            }
        }
        
        st.into_iter().collect()
    }
}
