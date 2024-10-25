#include <string>
#include <unordered_set>
#include <vector>
/*
 * Goal: Return all the folders with no sub-folders in the folders
 *
 * Intuition: We only need to check the sub directory path before the file for
 * eg the path is /a/b/c then we need to check whether there exists a folder
 * /a/b or /a if it does then we know that /a/b/c is a subfolder So basically we
 * will insert all the folder in the array into a set data structure, then
 * iterate through the array and check every single subpath of the folder.
 *
 * Time Complexity: O(n * L^2) L^2 is because the we try to search every single
 * subfolder within a folder so it will be L * L, the first L is iterate through
 * the folder and the second L is due to building the substr Space Complexity:
 * O(n)
 * */
class Solution {
public:
  std::vector<std::string> removeSubfolders(std::vector<std::string> &folder) {
    std::unordered_set<std::string> set{folder.begin(), folder.end()};
    std::vector<std::string> ans;

    for (const auto &folder_ : folder) {
      ans.emplace_back(folder_);
      for (int i{}; i < folder_.length(); i++)
        if (folder_[i] == '/' && set.count(folder_.substr(0, i))) {
          ans.pop_back();
          break;
        }
    }
    return std::move(ans);
  }
};
