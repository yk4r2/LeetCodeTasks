#include<iostream>
#include<vector>
#include<queue>


using std::vector, std::cout, std::endl, std::queue, std::pair;


class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    if (n == 1)
      return 0;

    int final_mask = (1 << n) - 1;
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(n, vector<bool> (final_mask + 1, false));

    for (int i = 0; i < n; ++i) {
      q.push({i, (1 << i)});
      seen[i][1 << i] = true;
    }
    int result = 0;

    while (!q.empty()) {
      int size = q.size();
      result++;
      while (size--) {
        pair<int, int> front = q.front();
        q.pop();
        int element = front.first;
        int elem_mask = front.second;

        for (int &child : graph[element]) {
          int new_mask = (1 << child) | elem_mask;
          if (new_mask == final_mask)
          return result;
          if (!seen[child][new_mask]) {
            q.push({child, new_mask});
            seen[child][new_mask] = true;
          }
        }
      }
    }
    return -1;
  }
};


int main() {
  vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
  cout << Solution().shortestPathLength(graph) <<'\n';
  return 0;
}

