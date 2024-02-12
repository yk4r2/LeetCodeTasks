// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        if root.is_none() {
            return Vec::new();
        }

        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut current_level: Vec<Rc<RefCell<TreeNode>>> = vec![root.unwrap()];

        while !current_level.is_empty() {
            let mut next_level = Vec::new();
            let mut current_values = Vec::new();

            for node in current_level.drain(..) {
                let node_borrowed = node.borrow();
                current_values.push(node_borrowed.val);

                if let Some(left) = node_borrowed.left.clone() {
                    next_level.push(left);
                }
                if let Some(right) = node_borrowed.right.clone() {
                    next_level.push(right);
                }
            }

            result.push(current_values);
            current_level = next_level;
        }

        result
    }
}

