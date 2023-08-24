impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut res = Vec::new();
        let mut cur = Vec::new();
        let mut num_of_letters: i32 = 0;

        for word in &words {
            if word.len() as i32 + cur.len() as i32 + num_of_letters > max_width {
                for i in 0..(max_width - num_of_letters) {
                    let idx = i as usize % (if cur.len() > 1 { cur.len() - 1 } else { cur.len() });
                    cur[idx] = format!("{} ", cur[idx]);
                }
                res.push(cur.join(""));
                cur.clear();
                num_of_letters = 0;
            }
            cur.push(word.clone());
            num_of_letters += word.len() as i32;
        }

        let last_line = cur.join(" ");
        res.push(format!("{:<width$}", last_line, width=max_width as usize));

        res
    }
}
