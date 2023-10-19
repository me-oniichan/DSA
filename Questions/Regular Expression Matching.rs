//pending
impl Solution {
    pub fn regex(s: &Vec<char>, p: &Vec<char>, i: usize, j: usize)-> bool{
        if j == p.len() && i==s.len(){
            return true;
        }
        else if j==p.len(){
            return false;
        }
        else if i==s.len() {
            return '*' == p.last().unwrap();
        }

        if p[j] == "."{
            return Solution::regex(s, p, i+1, j+1);
        }
        else if p[j] == "*"{
            for c in i..s.len(){
                if (Solution::regex(s,p,i+1, j+1)){
                    return true;
                }
            }
            return false;
        }

        else if p[j] != s[i] {
            return false;
        }

        return Solution::regex (s, p, i+1, j+1);
    }
    pub fn is_match(s: String, p: String) -> bool {
        let (size1, size2) = (s.len(), p.len());
        let s: Vec<char> = s.chars().collect();
        let p: Vec<char> = p.chars().collect();

        //let mut dp = vec![vec![0; size2]; size1];
        
        return Solution::regex(&s, &p, 0, 0);
    }
}
