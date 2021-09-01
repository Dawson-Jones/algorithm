impl Solution {
	pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
		people.sort_unstable();
		let (mut l, mut r, mut ans) = (0, people.len() - 1, 0);
		while l < r {
			if people[l] <= limit - people[r] {
			  l += 1;
			}
			r -= 1;
			ans += 1;
		}
  
		if l == r {
		  ans + 1
		} else {
		  ans
		}
	}
}