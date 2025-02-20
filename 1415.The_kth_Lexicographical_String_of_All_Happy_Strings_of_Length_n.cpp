#include <cmath>
#include <cstddef>
#include <string>
using std::string;

/*
 * Happy string:
 * Consists of only letters of the set [a, b, c]
 * s[i] != s[i + 1] for all values of i fomr 1 to s.length - 1
 * Goal: Return the kth string of this list or return an empty string if there are less than k happy string of length n.
 *
 * Intuition:
 * We need kth lexicographical string, so we at every place we need to place the smallest alphabetical number if
 * possible. This will lead to O(2^n) because of the s[i] != s[i + 1] If we draw out the decision tree, at the first
 * level we will have 3 choices and then the rest have only 2 choices. So the number of combinatoins will be 2^(n-1) * 3
 * and then we can observe that the order of leaf node is the same as the order of lexicographical string
 * Now come the question do we really need to compute all of the possible combination?
 * The answer is no, because if u observed clearly can partition the possible choices evenly.
 * Therefore, we only need to keep paritioned until we find the kth other that we want.
 * We can do it in linear time, because we only search through the partitoned that we want
 *
 * */
class Solution
{
  public:
    string getHappyString(int n, int k)
    {
        std::string choices{"abc"}, answer{};
        int ttlHappyStrings(std::pow(2, n - 1) * 3);

        // if the kth order is greater than the total number of happy string then impossible to form
        if (k > ttlHappyStrings)
            return "";

        int left{1}, right{ttlHappyStrings};

        for (int i{}; i < n; i++)
        {

            // compute the partition size
            int cur{left};
            int partitionSize((right - left + 1) / choices.length());
            int currLen(choices.length());

            // fill the word by finding the correct partition through partition by partition
            for (int j{}; j < currLen; j++)
            {
                // find the exact partition
                if (k >= left && k < left + partitionSize)
                {
                    answer += choices[j];
                    right = left + partitionSize - 1;
                    std::size_t pos = std::string{"abc"}.find(choices[j]);
                    if (pos != std::string::npos)
                    {
                        choices = std::string{"abc"}.erase(pos, 1);
                    }
                    break;
                }
                left += partitionSize;
            }
        }
        return answer;
    }
};
