#include <functional>
#include <vector>

/*
 * questions[i] = [pointsi, brainpoweri]
 * Must process the questions in order & make a decision whether to solve or skip each question
 * Solving question i will earn you pointsi points but u will unable to solve each of the next brainpoweri.
 * Skip Questoin i, you get to make the decision on the next problem.
 * eg: [[3,2], [4,3], [4,4], [2,5]]
 * if solve question 0 earn 3 points and unable to solve question 1 & 2.
 * If instead skip question 0 then i can choose solve or not solve question 1
 *
 * Goal: Return the maximum points you can earn
 *
 * Intuition:
 * This is actually a decision problem on whether choose or not choose. Then we can solve it naively by using dfs &
 * backtracking. O(2^n) We can further optimize it by using memoziatoin or caching. O(n) We can even further optiimze by
 * using dp (bottom up) Key observation: i. Finding the 'maximum' ii. This is somehow similar to 0/1 Knapsack problem
 * which involve profit & weight which at here is score & brainpower iii. Tree Decision Problem iv. Overlapping
 * subproblem
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    long long mostPoints(std::vector<std::vector<int>> &questions)
    {
        int nQuestion(questions.size());

        // 1. Recrusive & TopDown Memoziatoin/Caching
        // Optimize the recursive/naive approach by using caching, so we dont have to recompute
        // overlapping subproblem
        // cache[i] stands for the maximum score it can get from this index.
        // std::vector<long long> cache(nQuestion, -1);
        // std::function<long long(const int &)> dfs_backtracking = [&](const int &index) -> long long {
        //     if (index >= nQuestion)
        //         return 0LL;
        //
        //     // Utilize memoziation
        //     if (cache[index] != -1)
        //         return cache[index];
        //
        //     // Skip
        //     long long nxt = dfs_backtracking(index + 1);
        //     // Choose
        //     long long choose = questions[index][0] + dfs_backtracking(index + 1 + questions[index][1]);
        //
        //     return cache[index] = std::max(nxt, choose);
        // };
        //
        // return dfs_backtracking(0);

        // 2. Bottom Up (DP)
        // cache[i] stands for the maximum point it can get starting from index i
        std::vector<long long> cache(nQuestion, 0);
        for (int index{nQuestion - 1}; index >= 0; index--)
        {
            int points{questions[index][0]}, brainPower{questions[index][1]};

            long long skip = (index + 1 >= nQuestion) ? 0 : cache[index + 1];
            long long choose = points + (index + 1 + brainPower >= nQuestion ? 0 : cache[index + 1 + brainPower]);

            cache[index] = std::max(skip, choose);
        }

        return cache[0];
    }
};
