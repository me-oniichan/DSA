use std::collections::{HashMap, BTreeSet};

impl Solution {
    pub fn full_bloom_flowers(flowers: Vec<Vec<i32>>, people: Vec<i32>) -> Vec<i32> {
        let mut hmap = HashMap::new();
        let mut set = BTreeSet::new();

        for v in flowers{
            let (start, end) = (v[0], v[1]+1);

            hmap.entry(start).and_modify(|v| *v+=1).or_insert(1);
            hmap.entry(end).and_modify(|v| *v-=1).or_insert(-1);

            set.insert(start);
            set.insert(end);
        }

        let mut arr = Vec::new();
        
        for i in set{
            arr.push((i, *hmap.get(&i).unwrap()));
        }

        let mut prev=0;

        for (idx, val) in arr.iter_mut(){
            *val+=prev;
            prev = *val;
        }

        let mut ans = Vec::new();
        for p in people{
            let idx = match arr.binary_search_by(|v| v.0.cmp(&p)){
                Ok(x) => x as i32,
                Err(x) => x as i32 -1,
            };

            if idx < 0{
                ans.push(0);        
            }
            else {
                ans.push(arr[idx as usize].1);
            }
        }

        ans
        
    }
}
