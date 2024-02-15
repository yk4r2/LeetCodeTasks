use std::cmp;

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, mut new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut iter = intervals.into_iter().peekable();

        while let Some(interval) = iter.peek() {
            if interval[1] < new_interval[0] {
                result.push(iter.next().unwrap());
            } else {
                break;
            }
        }

        while let Some(interval) = iter.peek() {
            if interval[0] <= new_interval[1] {
                new_interval[0] = cmp::min(new_interval[0], interval[0]);
                new_interval[1] = cmp::max(new_interval[1], interval[1]);
                iter.next();
            } else {
                break;
            }
        }
        result.push(new_interval);
        result.extend(iter);

        result
    }
}
