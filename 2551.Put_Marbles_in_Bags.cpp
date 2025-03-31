#include <algorithm>
#include <vector>

/*
 * K bags and an array, weights where weights[i] is the weight of the ith marble.
 * Divide the marbles into the k bags with these rules:
 * i. No bag is empty
 * ii. If the ith marble and jth marble are in a bag, then all marbles with all index between the ith and jth indices
 * should be in the same bag.
 * iii. If a bag consists of all the marbels with an index from i to j inclusively, then the cost of the bag is
 * weights[i] + weights[j] Score after distributing the marble is the sum of the costs of all the k bags.
 *
 * Goal: Return the difference between the maximum and minimum scors among marble distributions.
 *
 * Intuition:
 * In simpler terms, we need to find way to divide the array into k arrays such that it will produce the maximum and
 * minimum score among marble distributions.
 * We only care the endpoints of each subarray because there where the computatoin of score is.
 * Another important observatoin is no matter how many k subarray we need to find we will always involve the first and
 * last element. So we can jus simply ignore it because in the end during the calculation of the difference between
 * maximum and minimum will be cancel out.
 * So we just need to find the k - 1 pair of ending value.
 * for eg: [1, 3, 5, 1] & k =2
 * possible split will be [1] & [3, 5, 1] || [1, 3] & [5, 1] || [1, 3, 5] & [1]
 * since k = 2, we only need to find k - 1 which is 1 pair of ending pair.
 * for example for this first one the score will be 1 + 1 + 3 + 1, 2nd is 1 + 3 + 5 + 1 & 3rd wil be  1 + 5 + 1 + 1
 * So from the observatoin that i state just konw, no matter how u split it u will always involve the first and last
 * element So we can simply just ignore it because in the end it gonna be cancel out during the subtraction so end up
 * with 1 + 3, 3 + 5, 5 + 1 so which is just k - 1 pair
 * So for maximum, we simply need to find the largest pair and for minimum it just another the way around
 * We can precompute the pairWeight first and sort it so that we can easily get the maximum and minimum
 * Time Complexity: O(nlgn)
 *
 * */
class Solution
{
  public:
    long long putMarbles(std::vector<int> &weights, int k)
    {
        int nMarbles(weights.size());

        // Base case
        if (k > nMarbles || k == nMarbles)
            return 0;

        std::vector<int> pairWeight;
        for (int i{}; i < weights.size() - 1; i++)
            pairWeight.emplace_back(weights[i] + weights[i + 1]);

        // sort the partitoin weight because we want to effectively to get the maximum and minimum
        // so pairWieght[i] is the sum of the ending point where partition happend at i and i + 1
        std::sort(pairWeight.begin(), pairWeight.end());

        long long answer{};
        for (int i{}; i < k - 1; i++)
            answer += pairWeight[nMarbles - i - 2] - pairWeight[i];

        return answer;
    }
};
