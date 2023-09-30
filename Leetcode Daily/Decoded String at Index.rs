impl Solution {
    pub fn decode_at_index(s: String, k: i32) -> String {
        let mut i=0 as usize;
        let mut k = (k-1) as usize;
        let mut n= 0 as usize;
        let mut j = 0 as usize;
        let s: Vec<char> = s.chars().collect();

        while n < k{
            n = match s[i].is_digit(10) {
                true => n-1,
                false => n
            };

            while s[i].is_digit(10){
                let num = s[i].to_digit(10).unwrap() as usize;
                n*=num;
                if n > k{
                    n/=num;
                    k%=(n+1);
                    i=0;
                    n=0;
                }
                else {
                    i+=1;
                }
            }
            
            i+= match s[i].is_digit(10) {
                true => 0,
                false => 1,
            }

        }

        s[i]
    }
}
