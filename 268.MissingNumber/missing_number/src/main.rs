impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        nums.len() as i32 * (nums.len() as i32 + 1) / 2 - nums.iter().sum::<i32>()
    }
}
