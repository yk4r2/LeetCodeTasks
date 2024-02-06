use std::cmp;

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let array_size = (amount + 1) as usize;
        let mut dynamic = vec![amount + 1; array_size];
        dynamic[0] = 0;

        for idx in 1..array_size {
            if let Some(min) = coins.iter()
                                    .filter(|&&c| (c as usize) <= idx)
                                    .map(|&c| dynamic[idx - c as usize])
                                    .min() {
                dynamic[idx] = min + 1;
            }
        }

        if dynamic[amount as usize] > amount { -1 } else { dynamic[amount as usize] }
    }
}

