use std::collections::HashMap;

impl Solution {
    pub fn find_least_num_of_unique_ints(arr: Vec<i32>, mut k: i32) -> i32 {
        let mut counter: HashMap<i32, i32> = HashMap::new();
        for element in arr.into_iter() {
            *counter.entry(element).or_insert(0) += 1;
        }
        let mut counts = counter.into_values().collect::<Vec<i32>>();
        counts.sort_unstable();
        let mut result: i32 = counts.len() as i32;

        for cnt in counts {
            if cnt - k <= 0 {
                k -= cnt;
                result -= 1;
            } else {
                break;
            }
        }
        result
    }
}

