impl Solution {
    pub fn largest_odd_number(num: String) -> String {
        let mut last = num.len();
        for (i, c) in num.chars().rev().enumerate(){
            if c.to_digit(10).unwrap()%2 != 0{
                last = i;
                break;
            } 
        }
        last = num.len() - last;
        num.get(..last).unwrap().to_string()
        
    }
}
