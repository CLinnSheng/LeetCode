#include <array>
#include <memory>
#include <string>

struct Nodes {
  std::array<std::shared_ptr<Nodes>, 26> alphabets;
  bool isWord;

  Nodes() : isWord{false} {
    std::fill(alphabets.begin(), alphabets.end(), nullptr);
  }
};

class WordDictionary {
private:
  std::shared_ptr<Nodes> root;

public:
  WordDictionary() { root = std::make_shared<Nodes>(); }

  // Time Complexity: O(n)
  void addWord(std::string word) {
    auto temp = root;

    for (const auto &c : word) {
      auto num_word = c - 'a';

      if (temp->alphabets[num_word] == nullptr)
        temp->alphabets[num_word] = std::make_shared<Nodes>();
      temp = temp->alphabets[num_word];
    }
    temp->isWord = true;
  }

  bool search(std::string word) {
    // use dfs for the ... part
    return dfs(word, 0, root);
  }

  bool dfs(std::string word, int index, std::shared_ptr<Nodes> root) {
    auto temp = root;

    for (int i = index; i < word.size(); i++) {

      // if '.' just search any nodes that available
      if (word[i] == '.') {
        for (auto &child : temp->alphabets)
          if (child != nullptr && dfs(word, i + 1, child))
            return true;
        return false;
      } else {
        if (temp->alphabets[word[i] - 'a'] == nullptr)
          return false;
        temp = temp->alphabets[word[i] - 'a'];
      }
    }
    return temp->isWord;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
