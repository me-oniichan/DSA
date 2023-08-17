use std::collections::VecDeque;

impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut mat = mat;
        let rows = mat.len() as i32;
        let cols = mat[0].len() as i32;

        let mut q = VecDeque::new();

        for i in 0..rows{
            for j in 0..cols{
                let r = i as usize;
                let c = j as usize;
                match mat[r][c] {
                    0 => {
                        q.push_back(vec![i,j]);
                    },
                    1 => {
                        mat[r][c] = -1;
                    },
                    _=> continue,
                }

            }
        }
        
        q.push_back(vec![-1,-1]);

        let mut dist = 1;
        let directions: Vec<Vec<i32>> = vec![vec![1,0], vec![0,1], vec![0,-1], vec![-1, 0]];
        
        loop {
            let cell = q.pop_front().unwrap();
            
            if cell[0] == -1 {
                dist+=1;
                match q.is_empty() {
                    true => {
                        break;
                    }
                    false => {
                        q.push_back(vec![-1,-1]);
                        continue;
                    }
                }
            }
            
            for i in &directions {
                let x = cell[0]+i[0];
                let y = cell[1]+i[1];

                if x >= 0 && y >= 0 && x < rows && y < cols && mat[x as usize][y as usize] == -1{
                    let r = x as usize;
                    let c = y as usize;

                    mat[r][c] = dist;
                   q.push_back(vec![x,y]);
                }
            }

        }
        mat

    }
}
