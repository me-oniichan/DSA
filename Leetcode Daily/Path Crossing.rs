use std::collections::HashSet;

impl Solution {
    pub fn is_path_crossing(path: String) -> bool {
        let (mut x, mut y) = (0,0);
        let mut hist = HashSet::new();
        hist.insert((0,0));
        for c in path.chars(){
            x+= match c {
                'E' => 1,
                'W' => -1,
                _ => 0
            };

            y+= match c {
                'N' => 1,
                'S' => -1,
                _ => 0
            };
            
            if let Some(v) = hist.get(&(x,y)){
                return true;
            }
            else {
                hist.insert((x,y));
            }
        }

        false
    }
}
