#include <queue>
#include <utility>
#include <vector>

/*
 * Given a 2d array classes where classes[i] = [passi, totali]. We know
 * beforehand that in ith classes there are totali total students but only passi
 * number of students pass the exam
 *
 * Another integer extraStudents where extraStudentss number of students that
 * are guaranteed to pass the exam. Assign each of the extraStudents students to
 * a class in a way that maximimzes the average pass ratio across all the
 * classes
 *
 * Goal: Return the maximum possible average pass ratio after assigning the
 * extraStudents students. Answer within 10^-5 of the actual naswer will be
 * accepted
 *
 * Intuition: We need to choose the class that add in the new student will
 * greatly increase the average pass ratio So every time we will be choosing the
 * 1 that increase the average pass ratio the most So we can use a maxHeap data
 * structure to pop out the 1 with the most great change
 *
 * */

struct comparator {
  bool operator()(const std::pair<double, std::pair<int, int>> &a,
                  const std::pair<double, std::pair<int, int>> &b) {
    return a.first < b.first;
  }
};

class Solution {
public:
  double maxAverageRatio(std::vector<std::vector<int>> &classes,
                         int extraStudents) {

    int n_class(classes.size());
    if (n_class == 1)
      return (double)classes[0][0] / classes[0][1];

    std::priority_queue<std::pair<double, std::pair<int, int>>,
                        std::vector<std::pair<double, std::pair<int, int>>>,
                        comparator>
        maxHeap;

    auto findChange = [](const int &passes, const int &total) {
      return ((double)(passes + 1) / (total + 1) - (double)passes / total);
    };

    for (const auto &class_ : classes)
      maxHeap.emplace(std::make_pair(findChange(class_[0], class_[1]),
                                     std::make_pair(class_[0], class_[1])));

    while (extraStudents) {
      auto [changePassRatio, classInfo] = maxHeap.top();
      maxHeap.pop();

      maxHeap.emplace(std::make_pair(
          findChange(classInfo.first + 1, classInfo.second + 1),
          std::make_pair(classInfo.first + 1, classInfo.second + 1)));
      extraStudents--;
    }

    double ans{};

    while (!maxHeap.empty()) {
      auto [_, classInfo] = maxHeap.top();
      maxHeap.pop();

      ans += (double)classInfo.first / classInfo.second;
    }

    return ans / n_class;
  }
};
