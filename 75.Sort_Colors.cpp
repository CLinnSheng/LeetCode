#include <utility>
#include <vector>

/*
 * The array nums with n object colored red, blue or white.
 * Goal; Sort them in place such that red, white and blue.
 *
 *
 * Intuition:
 * The simplest way is just find the indices of each individual color.
 * Then insert them into the nums array.
 * Time & Space Complexity: O(n)
 *
 * Can we make the space complexity to O(1)?
 * yes actually what we really need is just the index to insert the specific order
 * so we will have 3 var that store where should we place our ball for each individual color
 * */
class Solution
{
  public:
    void sortColors(std::vector<int> &nums)
    {
        // int red{}, blue{}, white{};
        // for (int i{}; i < nums.size(); i++)
        // {
        //     switch (nums[i])
        //     {
        //     case 0:
        //         red++;
        //         break;
        //     case 1:
        //         white++;
        //         break;
        //     case 2:
        //         blue++;
        //         break;
        //     }
        // }
        //
        // int index{};
        // while (red)
        // {
        //     nums[index] = 0;
        //     index++;
        //     red--;
        // }
        // while (white)
        // {
        //     nums[index] = 1;
        //     index++;
        //     white--;
        // }
        // while (blue)
        // {
        //     nums[index] = 2;
        //     index++;
        //     blue--;
        // }
        int n(nums.size());
        int red{}, white{}, blue{n - 1};

        // only need 1 pointer moving so we will be using white because white is in the middle,
        // if it ever other colors other than white just simply swap with the current index of red or blue
        while (white <= blue)
        {
            // swap with the current red index
            // we move red here because the sequence is from red, white, blue, if this is the first time encounter then
            // it must be white so we dont have to check again unlike the way how we update blue
            if (nums[white] == 0)
                std::swap(nums[red++], nums[white++]);
            else if (nums[white] == 1)
                white++;
            // we dont move the whit pointer here because we dont whats the blue containing
            else
                std::swap(nums[blue--], nums[white]);
        }
    }
};
