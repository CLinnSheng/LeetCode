#include <algorithm>
#include <cstdlib>
#include <vector>

/*
 * A good triplet (arr[i], arr[j], arr[k]) is good if following condition are true:
 * 0 <= i,j,k < arr.length
 * |arr[i]-arr[j]| <= a
 * |arr[j]-arr[k]| <= b
 * |arr[i]-arr[k]| <= c
 *
 * Goal: Return the number of good triplets
 *
 * Intuition:
 * The most easiest way is brute forec which is just triple loop
 * Time Complexity: O(n^3)
 *
 * Can we further optimize it?
 * is there any way to eliminate or reduce the number of loop?
 * If you notice one observation, we kinda need the information of the future in order to find the triplet
 * How about we use the information we have previously??--> prefix
 * so if you draw out in an event line
 *                <---------b--------->
 *       <----c----->
 *            i             j
 * so k have to be in the intersection point of b & c. So for the left boundary we get the right most and for the right
 * boundary we get the left most
 * then if you notice after we found the range we still have to go through another loop to check which fall into it.
 * So instead of using i & j, we use j & k. because we i must be smaller than j & k right (i<j<k).
 * And we also can use the information that we posses through prefix
 * i is in the intersection of these 2 conditions |arr[i] - arr[j]| <= a && |arr[i]-arr[k]| <= c
 * arr[i] = +/- a + arr[j] && arr[i] = +/- a + arr[k]
 * Time Complexity: O(n^2 + nM) where M is the maximum element
 * */
class Solution
{
  public:
    int countGoodTriplets(std::vector<int> &arr, int a, int b, int c)
    {
        // O(n^3)
        // int cnt{};
        // int n(arr.size());
        //
        // for (int i{}; i < n; i++)
        // {
        //     for (int j{i + 1}; j < n; j++)
        //     {
        //         if (std::abs(arr[j] - arr[i]) <= a)
        //         {
        //             for (int k{j + 1}; k < n; k++)
        //             {
        //                 if (std::abs(arr[k] - arr[j]) <= b && std::abs(arr[i] - arr[k]) <= c)
        //                     cnt++;
        //             }
        //         }
        //     }
        // }
        //
        // return cnt;

        int res{};
        // prefix[i] tells you how many element <= i
        std::vector<int> prefix(1001, 0);
        int n(arr.size());

        for (int j{}; j < n - 1; j++)
            for (int k{j + 1}; k < n; k++)
            {
                if (std::abs(arr[j] - arr[k]) <= b)
                {
                    // how many element before j where the abs conditions are met
                    int left_boundary{std::min(arr[j] - a, arr[k] - c)};
                    int right_boundary{std::min(arr[j] + a, arr[k] + c)};

                    left_boundary = std::max(left_boundary, 0);
                    right_boundary = std::min(1000, right_boundary);

                    // number of values of good i
                    if (left_boundary <= right_boundary)
                    {
                        res += prefix[right_boundary] -
                               (left_boundary == 0 ? 0 : prefix[right_boundary - left_boundary - 1]);
                    }
                }

                // update the prefix from arr[j] to 1000
                // because prefix[x] tells you the total number of element <= x
                for (int index{arr[j]}; index <= 1000; index++)
                    prefix[index]++;
            }

        return res;
    }
};
