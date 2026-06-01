#include <cmath>
#include <queue>
#include <vector>
using std::vector;

/*
 * Getting k closest point.
 * 'K' --> Can use a priority_queue or just sort it
 *
 * Time Complexity: O(nlgn)
 * Spaec Complexity: O(n)
 * */

struct Comparator
{

    bool operator()(const vector<int> &A, const vector<int> &B)
    {
        double distance_a = std::sqrt(pow(A[0], 2) + pow(A[1], 2));
        double distance_b = std::sqrt(pow(B[0], 2) + pow(B[1], 2));

        return distance_a > distance_b;
    };
};
class Solution
{
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        std::priority_queue<vector<int>, vector<vector<int>>, Comparator> minHeap;

        for (const auto &point : points)
        {
            minHeap.emplace(point);
        }

        vector<vector<int>> ans;

        while (k-- != 0)
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }

        return ans;
    }
};
