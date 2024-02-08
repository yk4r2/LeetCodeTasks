use std::cmp;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        
        let mut cumsum_array: Vec<i32> = Vec::with_capacity(nums.len());
        cumsum_array.push(nums[0]);
        for num in nums.iter().skip(1) {
            cumsum_array.push(cumsum_array.last().unwrap() + num);
        }
        let mut max_sum = cumsum_array[0];
        let mut min_from_end = 0;
        for &num in cumsum_array.iter() {
            max_sum = cmp::max(max_sum, num - min_from_end);
            min_from_end = cmp::min(min_from_end, num);
        }
        max_sum
    }
}
