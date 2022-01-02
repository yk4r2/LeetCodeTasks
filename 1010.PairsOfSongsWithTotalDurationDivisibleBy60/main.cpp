class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int freqs[60] = {}, res = 0;
    for (int t : time)
      freqs[t % 60]++;
    for (int i = 1; i < 30; i++)
      res += freqs[i] * freqs[60 - i];
    // special cases: 0 & 30
    res += freqs[0] * (freqs[0] - 1) / 2 + freqs[30] * (freqs[30] - 1) / 2;
    return res;
  }
};

