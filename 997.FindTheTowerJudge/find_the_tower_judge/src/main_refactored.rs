impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut trusts_cnt = vec![0; n as usize + 1];
        let mut trusted_cnt = vec![0; n as usize + 1];

        for pair in trust {
            trusts_cnt[pair[0] as usize] += 1;
            trusted_cnt[pair[1] as usize] += 1;
        }

        (1..=n as usize)
            .find(|&i| trusts_cnt[i] == 0 && trusted_cnt[i] == n - 1)
            .map_or(-1, |i| i as i32)
    }
}

