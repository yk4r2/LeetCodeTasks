#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>


using std::cout, std::endl, std::vector, std::unordered_map, std::queue;


class Solution {
 public:
  int minJumps(vector<int>& arr) {
	if (arr.empty())
	  return 0;
	queue<int> q{{0}};
	vector<bool> visited(arr.size(), false);

	unordered_map<int, vector<int>> equals;
	for (int i = 0; i < arr.size(); ++i)
	  equals[arr[i]].push_back(i);

	for (int steps = 0; !q.empty(); ++steps)
	  for (int i = q.size(); i > 0; --i) {
		auto current = q.front();
		q.pop();
		if (current == arr.size() - 1)
		  return steps;
		auto& next = equals[arr[current]];
		next.push_back(current - 1);
		next.push_back(current + 1);
		for (int n : next)
		  if (n >= 0 && n < arr.size() && !visited[n]) {
			q.push(n);
			visited[n] = true;
		  }
		next.clear();
	  }
	return arr.size() - 1;
  }
};


int main() {
  vector<int> example = {9, 1, 2, 3, 9};
  cout << Solution().minJumps(example);
}
