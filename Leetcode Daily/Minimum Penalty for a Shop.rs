impl Solution {
    pub fn best_closing_time(customers: String) -> i32 {
        let mut minp=0;
        let mut curp = 0;
        let mut earp = 0;

        for (i,c) in customers.chars().enumerate(){
            match c {
                'N' => curp+=1,
                _ => curp-=1,
            }

            if curp < minp{
                earp = i+1;
                minp = curp;
            }
        }

        earp as i32
    }
}
