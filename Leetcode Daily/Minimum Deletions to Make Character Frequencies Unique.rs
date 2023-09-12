impl Solution {
    pub fn min_deletions(s: String) -> i32 {
        let mut map = vec![0;26];

        for c in s.as_bytes(){
            let h = (*c-97) as usize;
            map[h]+=1;
        }

        map.sort();
        map.reverse();

        let mut ans = 0;
         
        
        loop {
            while(map.last().unwrap() == 0){
                map.pop();
            }
            for i in (1..map.len()).rev(){
                if(map[i]==map[i-1]){
                    map[i]-=1;
                    ans+=1;
                }
            }
            
            let mut flag = true;
            for i in 1..map.len(){
                if map[i] == map[i-1]{
                    flag = false;
                    break;
                }
            }

            if flag{
                break;
            }
        }
        ans
                
    }
}
