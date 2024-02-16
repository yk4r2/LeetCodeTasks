use std::collections::HashMap;

impl Solution {
    pub fn find_least_num_of_unique_ints(arr: Vec<i32>, mut k: i32) -> i32 {
        let counter = arr.into_iter()
                         .fold(HashMap::new(), |mut acc, x| {
                             *acc.entry(x).or_insert(0) += 1;
                             acc
                         });

        let mut counts: Vec<i32> = counter.values().cloned().collect();
        counts.sort_unstable();

        counts.iter().fold(counts.len() as i32, |res, &cnt| {
            if k >= cnt {
                k -= cnt;
                res - 1
            } else {
                res
            }
        })
    }
}

