impl Solution {
    pub fn get_winner(arr: Vec<i32>, k: i32) -> i32 {
        let mut i = 0_usize;
        let mut wins = 0;

        for j in 1..arr.len(){
            if arr[i] > arr[j]{
                wins+=1;
            }
            else {
                i=j;
                wins = 1;
            }
            if wins == k{
                break;
            }
        }

        arr[i]
    }
}
