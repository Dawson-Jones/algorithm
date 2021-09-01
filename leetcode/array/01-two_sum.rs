use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
      let mut map: HashMap<i32, usize> = HashMap::new();

      let mut n: i32;
      for (i, &num) in nums.iter().enumerate() {
          n = target - num;
          if let Some(&k) = map.get(&n) {
              return vec![k as i32, i as i32];
          }

          map.insert(num, i);
      }

      panic!()
    }
}

fn main() {
}