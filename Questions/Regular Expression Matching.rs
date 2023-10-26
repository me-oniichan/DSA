impl Solution {
    pub fn regex(s: &Vec<char>, p: &Vec<char>, i: usize, j: usize)-> bool{
        if s.len() == i && p.len() == j{
            return true;
        }
        else if p.len() == j{
            if j==16{
                println!("{j}");
            }
            return false;
        }
        else if s.len() == i{
            return j+1<p.len() && p[j+1]=='*' && Solution::regex(s,p,i,j+2);
        }
        
        if j+1 < p.len() && p[j+1] == '*'{
            if (s[i] == p[j] || p[j] == '.'){
                if Solution::regex(s,p, i, j+2) {
                    return true;
                }
                else if Solution::regex(s,p,i+1, j){
                    return true;
                }
            }
            else if Solution::regex(s,p, i, j+2) {
                return true;
            }
        }
        else if p[j] == '.' && Solution::regex(s,p,i+1,j+1) {
            return true;
        }
        else if p[j] == s[i] && Solution::regex(s,p,i+1,j+1){
            return true;
        }

        return false;
    }
    pub fn is_match(s: String, p: String) -> bool {
        let (size1, size2) = (s.len(), p.len());
        let s: Vec<char> = s.chars().collect();
        let p: Vec<char> = p.chars().collect();

        //let mut dp = vec![vec![0; size2]; size1];
        
        return Solution::regex(&s, &p, 0, 0);
    }
}





