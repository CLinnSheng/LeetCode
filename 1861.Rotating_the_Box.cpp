#include <vector>

/*
 * given a m*n matrix of characters box (side view). Each cell might contain
 * stone(#), obstacle(*) or empty(.) the box will be rotating 90 degrees
 * clockwise Goal: Return an n*m matrx represting the box after the rotation
 * describe
 *
 * Intuition: The stone either will fall to the most bottom or to the nearest
 * obstacle after rotation. Instead of searching from the top, it is more
 * efficient to search from the bottom then find the row with stone or obstacle.
 * This method is stimulation which will take O(m*n^2)
 *
 * Theres actually a more efficient method instead of keep finding the next
 * stone or obstacle in every cell we can actually just make use of 2 pointer, 1
 * point to the current available slot to put and another for iterating.
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 * */
class Solution {
public:
  std::vector<std::vector<char>>
  rotateTheBox(std::vector<std::vector<char>> &box) {
    int m = box.size();
    int n = box[0].size();

    // std::vector<std::vector<char>> rotateBox(n, std::vector<char>(m));

    // // fill the rotatebox by transpose it & need to reverse the value input
    // also
    // // O(mn)
    // for (int i{}; i < m; i++)
    //   for (int j{}; j < n; j++)
    //     rotateBox[j][i] = box[i][j];
    //
    // // O(m*n^2)
    // for (int i{}; i < n; i++)
    //   std::reverse(rotateBox[i].begin(), rotateBox[i].end());
    //
    // // then apply the gravity by searching from the bottom
    // for (int col{}; col < m; col++)
    //   for (int row{n - 1}; row >= 0; row--) {
    //     // found empty cell check above it is a stone or obstacle
    //     if (rotateBox[row][col] == '.') {
    //       // find the row with stone
    //       int rowWithStone{-1};
    //
    //       for (int k{row - 1}; k >= 0; k--) {
    //         // if met an obstacle then straightaway exit the loop
    //         if (rotateBox[k][col] == '*')
    //           break;
    //         else if (rotateBox[k][col] == '#') {
    //           rowWithStone = k;
    //           break;
    //         }
    //       }
    //
    //       // apply gravity if we found a stone above us
    //       if (rowWithStone != -1) {
    //         rotateBox[row][col] = '#';
    //         rotateBox[rowWithStone][col] = '.';
    //       }
    //     }
    //   }
    //
    for (int row{}; row < m; row++) {
      int currentAvailablecell{n - 1};
      for (int col{n - 1}; col >= 0; col--) {
        if (box[row][col] == '#') {
          box[row][col] = '.';
          box[row][currentAvailablecell--] = '#';
        } else if (box[row][col] == '*')
          currentAvailablecell = col - 1;
      }
    }

    std::vector<std::vector<char>> rotateBox;

    for (int col{}; col < n; col++) {
      std::vector<char> rotateBoxRow;
      for (int row{m - 1}; row >= 0; row--)
        rotateBoxRow.emplace_back(box[row][col]);

      rotateBox.emplace_back(rotateBoxRow);
    }
    return rotateBox;
  }
};
