const VOWELS: [u8; 10] = [65, 69, 73, 79, 85, 97, 101, 105, 111, 117];

impl Solution {
    pub fn sort_vowels(mut s: String) -> String {
        let bytes = unsafe { s.as_bytes_mut() };
        let mut nb_each_char = [0u32; 10];

        for (i, byte) in bytes.iter().enumerate() {
            match VOWELS.iter().position(|b| b == byte) {
                Some(index) => nb_each_char[index] += 1,
                _ => (),
            };
        }

        let mut vowels_iter = bytes.iter_mut().filter(|b| VOWELS.contains(b));
        for (i, count) in nb_each_char.iter_mut().enumerate() {
            let current_vowel = VOWELS[i];
            while *count > 0 {
                *vowels_iter.next().unwrap() = current_vowel;
                *count -= 1;
            }
        }
        s
    }
}
