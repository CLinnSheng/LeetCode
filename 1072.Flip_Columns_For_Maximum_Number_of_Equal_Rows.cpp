#include <string>
#include <unordered_map>
#include <vector>

/*
 * Given a m * n binary matrix
 * Choose any number of columns to flip every cell in that column
 * Goal: Return the maximum number of rows that have all values equal
 *
 * Intuition: Since we have 2 choices for every column flip it or not
 * So the time complexity of flipping it is O(2^n) & checking it will require
 * O(mn) Hence the total time complexity of naive approach is O(mn*2^n)
 *
 * Is there a better way?
 * We dont really need to flip the column, we can simplify it into 2 rows only.
 * We need to know how 2 rows can be the same? if and only if they have diff
 * bits at every single column eg: 001 & 110 if they flip the last column will
 * create 2 equal rows we can use a hash to keep track of the rows & then we
 * will favor 0 or 1 (we use 0 in this case) whenever we encounter a 0 bit in
 * the first column then we check whether the inverted row is exists in the hash
 * or not if it does add the count into it then we just need to get the row with
 * if 2 rows are not inverted of each other, no matter how u flip it the maximum
 * value of equal rows will only be 1 the maximum number of count
 *
 * Time Complexity: O(m * n^2)
 * Space Complexity: O(m * n)
 * */

class Solution {
public:
  int maxEqualRowsAfterFlips(std::vector<std::vector<int>> &matrix) {
    int row(matrix.size());
    int col(matrix[0].size());

    std::unordered_map<std::string, int> count;

    for (const auto &row : matrix) { // O(m)
      std::string rowStr;

      // convert it into a string
      for (const auto &val : row) // O(n)
        rowStr += std::to_string(val);

      // then see whether it start with 0 or 1
      if (rowStr[0] == '1') { // O(n)
        std::string invertedRowStr;
        for (const auto &ch : rowStr)
          invertedRowStr += ch == '1' ? '0' : '1';
        rowStr = invertedRowStr;
      }

      // update the hash
      count[rowStr]++;
    }

    // get the maximum count
    int ans{};

    for (const auto &[_, cnt] : count)
      ans = std::max(ans, cnt);

    return ans;
  }
};
