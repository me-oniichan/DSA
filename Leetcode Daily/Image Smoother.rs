impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut height = img.len();
        let mut width = img[0].len();

        let mut grid = vec![vec![0; width]; height];

        for i in 0..height{
            for j in 0..width{
                let mut sum = img[i][j];
                let mut denom = 1;
                
                if i as i32 -1 >=0 && j as i32 -1 >= 0{
                    sum+=img[i-1][j-1];
                    denom+=1;
                }
                
                if i as i32 -1 >= 0{
                    sum+=img[i-1][j];
                    denom+=1;
                } 

                if i+1 < height && j+1 < width{
                    sum+=img[i+1][j+1];
                    denom+=1;
                }

                if j+1 < width{
                    sum+=img[i][j+1];
                    denom+=1;
                }
                
                if i as i32 -1 >= 0 && j+1 < width{
                    sum+=img[i-1][j+1];
                    denom+=1;               
                }

                if i+1 < height{
                    sum+=img[i+1][j];
                    denom+=1;               
                }

                if i+1 < height && j as i32-1 >=0{
                    sum+=img[i+1][j-1];
                    denom+=1;               
                }

                if j as i32-1 >=0{
                    sum+=img[i][j-1];
                    denom+=1;               
                }

                grid[i][j] = sum/denom

            }
        }
        grid
    }
}
