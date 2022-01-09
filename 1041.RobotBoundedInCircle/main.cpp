#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::max, std::string;


class Solution {
 public:
  bool isRobotBounded(string instructions) {
  // current coords vector in (x, y)-form
  int current_vec[2] = {0, 0};
  // all turns possibilities clockwise in (x, y)-form
  int turns[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  // where is our robot pointing, index at turned list
  int index = 0;

  for (auto iteration : instructions) {
    if (iteration == 'L' || iteration == 'R') {
    // if we are turning left -> pointing ar index-1,
    // if right -> index+1
    index += iteration == 'L' ? -1 : 1;
    // because -1 % 4 is still -1 -> out of bounds error
    index = (index % 4 + 4) % 4;
    } else if (iteration == 'G') {
    // after all the turns going by the pointing vector
    current_vec[0] += turns[index][0];
    current_vec[1] += turns[index][1];
    }
  }
  // our robot stays in the circle iff it either changes direction...
  bool no_sideways_turn = !(turns[index][0] == 0 && turns[index][1] == 1);
  // ...or if it did not move at all!
  bool no_place_change = current_vec[0] == 0 && current_vec[1] == 0;

  return no_place_change || no_sideways_turn;
  }
};



int main() {
  cout << Solution().isRobotBounded("GGLLGG");
}
