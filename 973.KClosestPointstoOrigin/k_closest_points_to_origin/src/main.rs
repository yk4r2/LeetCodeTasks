use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: i32,
    x: i32,
    y: i32,
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}


impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, mut k: i32) -> Vec<Vec<i32>> {
        let mut heap = points
            .iter()
            .map(|point| {
            let (x, y) = (point[0], point[1]);
            let cost = x.pow(2) + y.pow(2);
            State { cost, x, y }
        })
        .collect::<BinaryHeap<_>>();

        let mut result = Vec::new();
        while k > 0 && !heap.is_empty() {
            if let Some(point) = heap.pop() {
                result.push(vec![point.x, point.y]);
                k -= 1;
            }
        }

        result
    }
}

