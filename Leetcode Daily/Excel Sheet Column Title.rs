impl Solution {
    pub fn convert_to_title(column_number: i32) -> String {
        let mut column_number = column_number;
        let mut ans = String::new();
        
        while column_number!=0 {
            let r = (column_number%26) as u32;
            column_number/=26;
            if r==0{
                column_number-=1;
            }
            let ch : char = match r {
                0 => 'Z',
                x => char::from_u32(x+64).unwrap(),
            };
            
            ans.push(ch);
        }

        ans.chars().rev().collect()

    }
}
