use std::{collections::HashMap, char};

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut hmap = HashMap::new();
        for i in strs{
            let mut chars: Vec<char> = i.chars().collect();
            chars.sort_unstable();
            let chars: String = chars.into_iter().collect();
            hmap.entry(chars).and_modify(|x| x.push(i.clone())).or_insert(vec![i]);
        }

        let mut ans = Vec::new();

        for (key, val) in hmap{
            ans.push(val);
        }
        ans
    }
}
