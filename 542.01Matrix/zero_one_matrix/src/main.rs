use std::collections::VecDeque;

impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = mat.len();
        let cols = mat[0].len();
        let mut result = vec![vec![i32::MAX; cols]; rows];
        let mut queue: VecDeque<(usize, usize)> = VecDeque::new();

        for i in 0..rows {
            for j in 0..cols {
                if mat[i][j] == 0 {
                    result[i][j] = 0;
                    queue.push_back((i, j));
                }
            }
        }

        let directions: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

        // BFS
        while let Some((r, c)) = queue.pop_front() {
            for (dr, dc) in directions.iter() {
                let new_r = r as isize + dr;
                let new_c = c as isize + dc;
                if new_r >= 0 && new_r < rows as isize && new_c >= 0 && new_c < cols as isize {
                    let new_r = new_r as usize;
                    let new_c = new_c as usize;
                    if result[new_r][new_c] > result[r][c] + 1 {
                        result[new_r][new_c] = result[r][c] + 1;
                        queue.push_back((new_r, new_c));
                    }
                }
            }
        }

        result
    }
}

