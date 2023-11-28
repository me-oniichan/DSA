impl Solution {
    pub fn number_of_ways(corridor: String) -> i32 {
        let modulo = 1000000007;
        let mut ans: i64 = 1;
        let mut seats = 0;
        let mut plants = 0;

        for x in corridor.chars() {
            if x == 'S' {
                seats += 1;
                if seats == 3 {
                    seats = 1;
                    ans = ((plants + 1) * ans) % modulo;
                }
                plants = 0;
            }
            else {
                plants += 1;
            }
        }

        if seats != 2 {
            return 0;
        }
        ans as i32
    }
}
