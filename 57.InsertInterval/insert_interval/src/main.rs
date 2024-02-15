use std::cmp;

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, mut new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut i: usize = 0;
        let n = intervals.len();
    
        while (i < n) && (intervals[i][1] < new_interval[0]) {
            result.push(intervals[i].clone());
            i += 1;
        }
        while (i < n) && (intervals[i][0] <= new_interval[1] && intervals[i][1] >= new_interval[0]) {
            new_interval[0] = cmp::min(new_interval[0], intervals[i][0]);
            new_interval[1] = cmp::max(new_interval[1], intervals[i][1]);
            i += 1;
        }
        result.push(new_interval);
        while i < n {
            result.push(intervals[i].clone());
            i += 1;
        }
        result
    }
}
