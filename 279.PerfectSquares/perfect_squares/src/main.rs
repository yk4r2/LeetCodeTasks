use std::cmp;

impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let mut dynamic = vec![i32::MAX; (n + 1) as usize];
        dynamic[0] = 0;

        let mut squares: Vec<i32> = Vec::new();
        let mut i = 1;
        while i * i <= n {
            squares.push(i * i);
            i += 1;
        }

        for idx in 1..=n as usize {
            for &sq in &squares {
                if sq as usize > idx {
                    break;
                }
                dynamic[idx] = cmp::min(dynamic[idx], dynamic[idx - sq as usize] + 1);
            }
        }
        dynamic[n as usize]
    }
}

