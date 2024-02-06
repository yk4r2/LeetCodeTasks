use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut counter: HashMap<String, Vec<String>> = HashMap::new();

        for string in strs.into_iter() {
            let mut chars: Vec<char> = string.chars().collect();
            chars.sort_unstable();
            let sorted_key: String = chars.into_iter().collect();
            counter.entry(sorted_key).or_insert(Vec::new()).push(string);
        }
        counter.into_values().collect()
    }
}

