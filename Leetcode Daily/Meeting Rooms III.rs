use std::{collections::BinaryHeap, cmp::Reverse};

impl Solution {
    pub fn most_booked(n: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        let N = n as usize;
        let mut table = vec![0; N];
        let mut rooms = vec![true; N];
        let mut pq: BinaryHeap<(Reverse<i64>, Reverse<usize>)> = BinaryHeap::new();
        let mut available = 0_usize; 
        meetings.sort();

        for meeting in meetings{
            while let Some(&(Reverse(end), Reverse(index))) = pq.peek() {
                if end <= meeting[0_usize] as i64{
                    available = available.min(index);
                    rooms[index] = true;
                    pq.pop();
                }
                else {
                    break;
                }
            }
            if available == N{
                if let Some(&(Reverse(end), Reverse(index))) = pq.peek(){
                    let new_val = (Reverse(end+meeting[1] as i64-meeting[0] as i64), Reverse(index));
                    table[index]+=1;
                    pq.pop();
                    pq.push(new_val);
                }
            } 
            else {
                table[available]+=1;
                pq.push((Reverse(meeting[1] as i64), Reverse(available)));
                rooms[available] = false;
                for i in available..N{
                    if rooms[i] == true{
                        available = i;
                        break;
                    }
                }
                if rooms[available] == false{
                    available = N;
                }
            }

        }

        let mut max = 0_usize;
        let mut max_elem = table[0];
        for (i, e) in table.into_iter().enumerate(){
            if e >  max_elem{
                max = i;
                max_elem = e;
            } 
        }

        max as i32
    }
}
