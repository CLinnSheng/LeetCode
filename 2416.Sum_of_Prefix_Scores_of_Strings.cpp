#include <ios>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*
 * Score of a string word as the number of strings. words[i] such that word is a
 * prefix of words[i] eg: if words = ['a', 'ab', 'ab', 'abc', 'cab'] then the
 * score of 'ab' is 2 since 'ab' is the prefix of both 'ab' and 'abc' Goal:
 * Return an  array answer of size n where answer[i] is the sum of scores of
 * every non-empty prefix of words[i]
 *
 * Intuition:
 * Using hashi data structure to store and keep track of all the prefixses while
 * we iterate through the words. After prepopulate the hash, we just have to
 * iterate through the words again to check the score of every single word in
 * the words just by using hashing. However, this is very expensive Time
 * Complexity: n to iterate through the words and lets say the amximum length of
 * a word is L and then we still need to create substr for every single prefix
 * this will cost L also so the total time complexity will be O(n*L*L)
 *
 * What we can improve from previous method is instead of using slicing method
 * to create substtr we use a prefix tree method Where everytime we encounter a
 * new method we will just add create a new node in tree and just extend from
 * the previous prefix if available This reduce the time complexity to O(N*L)
 * Space COmplexity: O(n)
 * */

struct Prefix_Tree_Node {
  std::array<Prefix_Tree_Node *, 26> children;
  int cnt = 0;

  Prefix_Tree_Node() : children{nullptr} {}
};

class Solution {
private:
  Prefix_Tree_Node *root = new Prefix_Tree_Node();

  void insert(const string &word) {
    auto temp_ptr = root;

    for (const auto &c : word) {
      // if is a new prefix, we create new node branch from the previous prefix
      if (temp_ptr->children[c - 'a'] == nullptr)
        temp_ptr->children[c - 'a'] = new Prefix_Tree_Node();
      temp_ptr = temp_ptr->children[c - 'a'];
      temp_ptr->cnt++;
    }
  }

  int count(const string &word) {
    auto temp_ptr = root;
    int count_ = 0;

    for (const auto &c : word) {
      count_ += temp_ptr->children[c - 'a']->cnt;
      temp_ptr = temp_ptr->children[c - 'a'];
    }
    return count_;
  }

public:
  std::vector<int> sumPrefixScores(std::vector<std::string> &words) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (words.size() == 0)
      return {};

    std::vector<int> ans;

    // Creating the tree
    for (const auto &word : words)
      insert(word);

    // Counting scores
    for (const auto &word : words)
      ans.emplace_back(count(word));

    return ans;
  }
};
