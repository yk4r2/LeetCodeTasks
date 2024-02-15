impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i64 {
        nums.sort_unstable();
        let mut cum_sum: Vec<i64> = Vec::with_capacity(nums.len());
        cum_sum.push(nums[0] as i64);
    
        for (iter, &element) in nums.iter().enumerate().skip(1) {
            cum_sum.push(element as i64 + cum_sum[iter - 1]);
        }
        for (iter, &element) in nums.iter().enumerate().rev() {
            if iter == 0 {
                break;
            }
            if (element as i64) < cum_sum[iter - 1] {
                return cum_sum[iter];
            }
        }
        -1
    }
}

