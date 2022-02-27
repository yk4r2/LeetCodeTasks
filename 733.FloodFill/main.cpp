nclude<iostream>


using std::max, std::cout, std::endl, std::pair, std::vector;


class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image,
                                int sr, int sc, int newColor) {
    int curr_color = image[sr][sc];
    dfs(sr, sc, newColor, curr_color, image);
    return image;
  }

  void dfs(int x, int y, int new_color, int old_color,
           vector<vector<int>> &image) {
    image[x][y] = new_color;

    int x_add[] = {-1, 0, 1, 0};
    int y_add[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; ++i) {
      int a = x + x_add[i];
      int b = y + y_add[i];

      if (a >= 0 && a < image.size() && b >= 0 &&
          b < image[0].size() && image[a][b] == old_color &&
          image[a][b] != new_color)
      dfs(a, b, new_color, old_color, image);
    }
  }
};


int main() {
  vector<vector<int>> input = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  for (auto row : Solution().floodFill(input, 1, 1, 2)) {
    for (auto element  : row)
      cout << element << " ";
    cout << "\n";
  }
  return 0;
}

