#include <algorithm>
#include <vector>

/*
 * Given a 0 indexed array of n integers, differences. differences[i] = hidden[i + 1] - hidden[i]
 * differences describe the differences between each pair of consecutive integers of a hidden integer of length n + 1
 *
 * lower & upper describe the inclusive range of values [lower, value] that the hidden sequence can contain
 *
 * Goal: Return the number of possible hidden seuqnces that are
 *
 *
 * Intuition:
 * Key observation is that the hidde sequence is length of n + 1
 * and also we only need to fix the first element. Then rest of the element can be formed just by following the sequence
 * of differences.
 *
 *
 * The brute force way will just try every single possible first element within the range
 * the time complexity: O(n^2)
 *
 * if we let the first element be x & differences=[1,-3,4,-1] --> hidden=[a,b,c,d,e]
 * a = x, b = x + 1, c = x - 2, d = x + 2, e = x + 3
 * Notice that the maximum value is x + 2 and minimum value is x - 2.
 * So we need to find all possible value of x such that the maximum and minimum value is within thr ange of [lower,
 * upper]. Let's move this into the graph of [lower, upper] and we fix the minimum value at lower. so the upper will be
 * at lower + 4. From the graph, we can observe there is some gap between the maximum value and upper. So that tell us
 * how much we can shift the graph in another way how many possible x is there.
 *
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int numberOfArrays(std::vector<int> &differences, int lower, int upper)
    {
        int minVal{}, maxVal{};
        int currVal{};

        for (const int &diff : differences)
        {
            currVal += diff;
            minVal = std::min(minVal, currVal);
            maxVal = std::max(maxVal, currVal);
        }

        int answer{(upper - lower + 1) - (maxVal - minVal)};

        return answer > 0 ? answer : 0;
    }
};
