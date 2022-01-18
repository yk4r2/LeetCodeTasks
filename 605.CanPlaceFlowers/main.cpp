class Solution {
 public:
  bool canPlaceFlowers(vector<int> flowerbed, int n) {
    int current = 0; const int size = flowerbed.size();
    for (int i = 0; i <= size; i++)
      if (i < size && flowerbed[i] == 0) {
        current++;
        if (i == 0)
          current++;
        if (i == size - 1)
          current++;
      } else {
        n -= (current - 1) / 2;
        if (n <= 0)
          return true;
        current = 0;
      }
    return false;
  }
};
