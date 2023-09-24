impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let s1=s.len();
        let s2=t.len();
        if s1==0{
            return true;
        }
        else if (s2< s1){
            return false;
        }
        let s= s.as_bytes();
        let t=t.as_bytes();
        let mut i = 0;
        for j in 0..s2{
            if s[i] == t[j]{
                i+=1;
                if i==s1{
                    return true;
                }
            }
            
        }
        return false;

    }
}

