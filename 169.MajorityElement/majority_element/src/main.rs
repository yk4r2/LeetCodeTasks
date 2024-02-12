impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut cand = 0;
        let mut count = 0;
        for &num in nums.iter() {
            if count == 0 {
                cand = num;
            }
            count += if cand == num { 1 } else { -1 };
        }
        cand
    }
}

