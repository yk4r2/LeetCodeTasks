#include<iostream>
#include<vector>
#include<stack>


using std::cout, std::endl, std::vector, std::stack, std::max;


class Solution {
 public:
  int largestRectangleArea(vector<int> heights) {
    stack<int> st;
    st.push(-1);
    int max_area = 0;
    for (int i = 0; i < heights.size(); ++i) {
      while (st.top() != -1 && heights[st.top()] >= heights[i]) {
        int height = heights[st.top()];
        st.pop();
        int width = i - st.top() - 1;
        max_area = max(max_area, height * width);
      }
      st.push(i);
    }
    while (st.top() != -1) {
      int height = heights[st.top()];
      st.pop();
      int width = static_cast<int>(heights.size()) - st.top() - 1;
      max_area = max(max_area, height * width);
    }
    return max_area;
  }
};


int main() {
  vector<int> input = {2, 1, 5, 6, 2, 3};
  cout << Solution().largestRectangleArea(input) << endl;
  return 0;
}
