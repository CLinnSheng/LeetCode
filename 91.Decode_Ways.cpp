#include <string>

class Solution {
public:
  int numDecodings(std::string s) {
    int len(s.length());

    if (len == 1)
      return 1;
    if (s[0] == '0')
      return 0;

    int ans{1};
    for (int i{1}; i < len; i++) {
      std::string temp{s.substr(i - 1, 2)};
      if (temp[0] != '0' && std::stoi(temp) >= 10 && std::stoi(temp) <= 26)
        ans++;
      if (s[i] != '0')
        ans++;
    }

    return ans;
  }
};
