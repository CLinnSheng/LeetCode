#include <queue>
#include <utility>
#include <vector>
using std::vector, std::priority_queue;
/*
 * classes[i] = [pass_i, total_i], another extraStudents that guaranteed pass the exam
 * Assign each of the extraStudents to a class in a way to maximize the average pass ratio across the class
 * Goal: Return the average pass ratio
 *
 * Intuition:
 * So we trying to assign the extraStudent to maximize the pass ratio across the class. So we will assign to classes
 * that have lower pass ratio. Then how can we easily access classes with lower pass ratio? We can make use of heap to
 * easily access the class with low pass ratio.
 * One important thing that adding to lowest class with pass ratio doesnt mean will increase the average pass ratio, so
 * instead of determine through the pass ratio. We use increase in ratio
 * Time Complexity: O(nlgn)
 *
 * */
struct comparator
{
    template <typename T> bool operator()(const T &A, const T &B)
    {
        return A.first < B.first;
    }
};
class Solution
{
  public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>,
                            comparator>
            maxHeap;

        auto findChange = [&](const auto &pass, const auto &ttlStudent) {
            return (((double)pass + 1) / (ttlStudent + 1)) - ((double)pass / ttlStudent);
        };

        for (const auto &class_ : classes)
            maxHeap.emplace(findChange(class_[0], class_[1]), std::make_pair(class_[0], class_[1]));

        while (extraStudents)
        {
            auto top{maxHeap.top()};
            maxHeap.pop();

            maxHeap.emplace(findChange(top.second.first + 1, top.second.second + 1),
                            std::make_pair(top.second.first + 1, top.second.second + 1));

            extraStudents--;
        }

        double sumRatio{};
        while (!maxHeap.empty())
        {
            auto top{maxHeap.top()};
            maxHeap.pop();

            sumRatio += (double)top.second.first / top.second.second;
        }

        return sumRatio / classes.size();
    }
};
