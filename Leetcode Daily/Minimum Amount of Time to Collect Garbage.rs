impl Solution {
    pub fn garbage_collection(garbage: Vec<String>, mut travel: Vec<i32>) -> i32 {
        let mut prev = 0;
        travel.insert(0, 0);
        for i in travel.iter_mut(){
            *i+=prev;
            prev = *i;
        }

        let mut ansg = 0;
        let mut ansm = 0;
        let mut ansp = 0;
        let (mut m, mut p, mut g) = (0,0,0);

        for (i, garb) in garbage.iter().enumerate(){

            for c in garb.chars(){
                match c {
                    'G' => {
                        g+=1;
                        ansg = travel[i-1];
                    },
                    'P' => {
                        p+=1;
                        ansp = travel[i-1];
                    },
                    'M' => {
                        m+=1;
                        ansm = travel[i-1];
                    },
                    _ => {}
                }
            }
        }

        (ansp+ansg+ansm) as i32 +p+g+m
    }
}
