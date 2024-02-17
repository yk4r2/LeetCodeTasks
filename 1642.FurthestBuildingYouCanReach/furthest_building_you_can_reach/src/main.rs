use std::collections::BinaryHeap;

impl Solution {
    pub fn furthest_building(heights: Vec<i32>, mut bricks: i32, ladders: i32) -> i32 {
        let mut heap = BinaryHeap::new();

        for i in 0..(heights.len() - 1) {
            let diff = heights[i + 1] - heights[i];
            if diff <= 0 {
                continue
            }
            heap.push(-diff);
            if heap.len() > ladders as usize {
                bricks += &heap.pop().unwrap();
            }
            if bricks < 0 {
                return i as i32;
            }
        }
        heights.len() as i32 - 1
    }
}

