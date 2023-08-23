impl Solution {
    pub fn reorganize_string(s: String) -> String {
        let mut table : Vec<i32>= vec![0; 26];

        for c in s.chars(){
            table[c as usize - 97]+=1;
        }
        
        let mut l=0 as usize;
        let mut max = 0;

        for i in 0..26 as usize {
            if table[i] > max{
                l=i;
                max = table[i];
            }
        }

        if max as usize > (s.len()+1)/2{
            return String::new();
        }
        
        let mut ans: Vec<u8> = vec![0; s.len()];
        
        let mut index=0 as usize;
        while table[l] > 0{
            ans[index] = (l+97) as u8;
            index+=2;
            table[l]-=1;
        }
        
        for i in 0..26{
            while table[i] > 0{
                if index >= s.len(){
                    index=1;
                }

                ans[index]= (i+97) as u8;
                index+=2;
                table[i]-=1;
            }
        }

        String::from_utf8(ans).unwrap()

    }
}
