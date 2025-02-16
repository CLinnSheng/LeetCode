#include <vector>
/*
 *Given an integer n, find a sequence that satisfies all of the following:

    The integer 1 occurs once in the sequence.
    Each integer between 2 and n occurs twice in the sequence.
    For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.

The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a
solution.

 * Intuition:
 * First thought will be using brute force and backtrack if we couldnt make it
 * Also being greedy at the same time, every tiem we place a number we will place the largest value first and then also
place the next element
 * by following the rules which is place at n[i] away from i
 *
 * Time Complexity: O(n!) because we using backtracking to try all every single possible permutation
 * */
class Solution
{
  private:
    bool helper(std::vector<int> &answer, std::vector<bool> &numberPlaced, const int &n, const int &index)
    {
        // base case
        // see we fill fin already or not
        if (index == answer.size())
            return true;

        // if the current position already filled
        // move to the next one
        if (answer[index] != 0)
            return helper(answer, numberPlaced, n, index + 1);

        // if no we will try to placed it
        // we trying to be greedy and place from the highest possible number first
        for (int i{n}; i >= 1; i--)
        {
            // if this number already been placed move on to the next 1
            if (numberPlaced[i])
                continue;

            // otherwise mark it and try to place it
            numberPlaced[i] = true;
            answer[index] = i;

            // we will palce another also at index + i
            //    but we need to check what value is i because only '1' need to place once
            if (i == 1)
            {
                // move on to another index to continue filling in
                if (helper(answer, numberPlaced, n, index + 1))
                    return true;
            }
            else if (index + i < answer.size() && answer[index + i] == 0)
            {
                // fill it and then continue to the next index
                answer[index + i] = i;
                if (helper(answer, numberPlaced, n, index + 1))
                    return true;

                answer[index + i] = 0;
            }

            // backtracking means the placement starting from this value is not correct
            // move on to the next value
            answer[index] = 0;
            numberPlaced[i] = false;
        }
        return false;
    }

  public:
    std::vector<int> constructDistancedSequence(int n)
    {
        // Only have 2 * n - 1 elements
        std::vector<int> answer(n * 2 - 1, 0);
        // track which number is being used already because at once we straight away place 2
        std::vector<bool> numberPlaced(n + 1, false);

        helper(answer, numberPlaced, n, 0);
        return answer;
    }
};
