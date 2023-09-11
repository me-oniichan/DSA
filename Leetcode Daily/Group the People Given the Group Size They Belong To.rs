use std::collections::HashMap;

impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let mut map: HashMap<i32, Vec<i32>> = HashMap::new();

        for (index,i) in group_sizes.iter().enumerate(){
           match map.get_mut(i) {
                None => {
                    map.insert(*i, vec![index as i32]);
                },
                Some(x)=>{
                    x.push(index as i32)
                }
            } 
        }

        let mut ans = Vec::new();

        for (key, value) in map.iter() {
            let mut i =0;
            while i < value.len() {
                let mut grp = Vec::new();
                let mut count=0;

                while &count < key{
                    grp.push(value[i]);
                    i+=1;
                    count+=1;
                }
                ans.push(grp);
            }

        }

        ans
    }
}
