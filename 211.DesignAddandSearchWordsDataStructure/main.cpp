#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::string;


class WordDictionary {
  vector<WordDictionary*> children;
  bool isWordEnd;

 public:
  WordDictionary(): isWordEnd(false) {
    children = vector<WordDictionary*> (26, nullptr);
  }

  void addWord(string word) {
    WordDictionary* current = this;
    for (char c : word) {
      if (current->children[c - 'a'] == nullptr)
        current->children[c - 'a'] = new WordDictionary();
      current = current->children[c - 'a'];
    }
    current->isWordEnd = true;
  }

  bool search(string word) {
    WordDictionary* current = this;
    for (int i = 0; i < word.size(); ++i) {
      char c = word[i];
      if (c == '.') {
        for (auto ch : current->children)
          if (ch && ch->search(word.substr(i + 1)))
          return true;
        return false;
      }
      if (current->children[c - 'a'] == nullptr)
        return false;
      current = current->children[c - 'a'];
    }
    return current && current->isWordEnd;
  }
};



int main() {
  return 0;
}
