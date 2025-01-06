#include <string>
#include <vector>

/*
 * Goal: Return an array answer of size n where answer[i] is the minimum number of operations needed to move all the
 * balls to ith box.
 *
 * Intuition:
 * We can done it by brute box with double loop.
 * once from the left and once from the right
 * Time Complexity: O(n^2)
 *
 * How can we optimize from the brute force and reduce it to linear time?
 * If we observer from the brute force the array is in increasing.
 * eg: from the left
 * the answer is [11, 8, 5, 3, 1, 0] & the number of balls is 3 & the boxes = [0, 0, 1, 0, 1, 1]
 * we observe the answer[i + 1] is actually minus the ball it had at ith boxes with answer[i]
 * */
class Solution
{
  public:
    std::vector<int> minOperations(std::string boxes)
    {
        int len(boxes.length());
        std::vector<int> answer(len, 0);

        int balls{}, moves{};
        // from the left
        for (int i{}; i < len; i++)
        {
            answer[i] = balls + moves;
            moves += balls;
            if (boxes[i] == '1')
                balls++;
        }

        // from the right
        balls = moves = 0;
        for (int i{len - 1}; i >= 0; i--)
        {
            answer[i] += balls + moves;
            moves += balls;
            if (boxes[i] == '1')
                balls++;
        }
        return answer;
    }
};
