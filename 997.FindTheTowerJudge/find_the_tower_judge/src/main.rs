impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut trusts_cnt: Vec<i32> = vec![0; n as usize + 1];
        let mut trusted_cnt: Vec<i32> = vec![0; n as usize + 1];

        for pair in trust.iter() {
            trusts_cnt[pair[0] as usize] += 1;
            trusted_cnt[pair[1] as usize] += 1;
        }

        let mut result: i32 = -1;
        for i in 1..=n as usize {
            if trusts_cnt[i] == 0 && trusted_cnt[i] == n - 1 {
                result = i as i32;
                break;
            }
        }
        result
    }
}

