#include <algorithm>
#include <deque>
#include <vector>
/*
 * Given a list of int array heights
 * Goal: FInd all the builiding that can veiw the height.
 * Eg: 4,2,3,1
 * Only [0,2,3] can see the ocean
 *
 * Intuition:
 * If you observe the last building can always see the building.
 * And you notice the answer must be descending order, in order for the buildings in front to see the ocean
 *
 * This give us an intuition of using a monotomic stack
 * Or an easier way is actually be greedy start from the back
 * since we know the last building will always view the ocean we just have to find all those buildiing taller than the
 * right most tallest building.
 *
 * */
class Solution
{
  public:
    std::vector<int> findBuildings(std::vector<int> &heights)
    {
        std::vector<int> answer;
        int n(heights.size());

        // Approach 1: Monotomic Stack
        for (int i{}; i < n; i++)
        {
            // Check whether the current building got block the front builiding or not.
            // If got then all the front building cannot view the ocean
            while (!answer.empty() && heights[i] > heights[answer.back()])
                answer.pop_back();

            answer.emplace_back(i);
        }
        //

        // Approach 2: Greedy (From the Back)
        if (n > 0)
            answer.emplace_back(n - 1);

        int maxHeight{heights[n - 1]};

        for (int i{n - 2}; i >= 0; i--)
        {
            if (heights[i] > maxHeight)
            {
                answer.emplace_back(i);
                maxHeight = heights[i];
            }
        }
        std::reverse(answer.begin(), answer.end());
        //
        return answer;
    }
};
