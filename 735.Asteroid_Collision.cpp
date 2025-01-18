#include <deque>
#include <vector>

/*
 * Indices of the asteriod in the array represent their relative position in space
 * Each asteroid, the absolute value represent the size & sign represent its direction (+ right, - left)
 * Each of it moving at the same speed
 *
 * Goal: Find out the state of the asteroids after all collisions. if 2 meet, smaller one will explode. If both same
 * size, both explode NOTE: 2 moving at the same speed would never meet
 *
 * Intuition:
 * We need to find out whether the asteroid will collide or not.
 * The only we care is about the direction and then since the question stated the indices indicate their relative
 * position in space. So asteroid[i] will only collide with asteroid[i - 2] if & only if asteroid[i] collides with
 * asteroid[i - 1] first and in different directions. The best data structure to use is stack
 * IMPORTAN ONLY INCOMING RIGHT WILL COLLIDE WITH LEFT, so not neccessary in differnt direction they will collide like
 * left & right
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */

class Solution
{
  public:
    std::vector<int> asteroidCollision(std::vector<int> &asteroids)
    {
        // treat the stack goes in the right direction only
        std::deque<int> stack;

        for (const auto &asteroid : asteroids)
        {
            bool collision{false};
            // coming asteroid from the right(<0), and previous asteroid from the left(>0).
            // Collision only happen
            while (!stack.empty() && asteroid < 0 && stack.back() > 0)
            {
                int diff_in_size{asteroid + stack.back()};

                // coming asteroid is bigger
                // the previous asteroid will explode
                if (diff_in_size < 0)
                    stack.pop_back();
                // previous asteroid is bigger
                else if (diff_in_size > 0)
                {
                    collision = true;
                    // straigh away break because all the asteroid in the stack is in the same direction
                    break;
                }
                // same size
                else
                {
                    stack.pop_back();
                    collision = true;
                    break;
                }
            }
            if (!collision)
                stack.emplace_back(asteroid);
        }
        return std::vector<int>(stack.begin(), stack.end());
    }
};
