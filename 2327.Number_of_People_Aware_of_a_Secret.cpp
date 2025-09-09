
/*
 *  Each person will share a secret with a new person every day starting from delay days after discovering the secret.
 *  Each person will forget the secret after forget days after discovering the secret.
 *
 *  Goal: Return the number of people who know the secret at the end of n days
 *
 *  Intuition:
 *  We need to keep track of the number of people who have discovered the secret and the day the discovered it, so we
 * can remove it from the list after forget days
 * We can actually stimulate it. We can use a deque to store the people have know and people who have share it
 * Process:
 * 1. Check whether they can start to share already or not
 * 2. Check whether they forget already or not
 * 3. Then make everyone that can share share the secret
 *
 * Time Complexity: O(n)
 *
 * */
#include <deque>
#include <utility>
class Solution
{
  public:
    constexpr static int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        // first -> days, second -> number of people
        std::deque<std::pair<int, int>> know, share;
        know.emplace_back(1, 1);
        int knwCnt{1}, shrCnt{0};

        for (int i{1}; i <= n; i++)
        {
            // First check the people in the know list, to see whether they can share already or not
            if (!know.empty() && i - know[0].first == delay)
            {
                // Then push it into share list
                auto val{know.front()};
                know.pop_front();

                knwCnt = (knwCnt - val.second + MOD) % MOD;

                // Update the share cnt and push into the list
                shrCnt = (shrCnt + val.second) % MOD;
                share.emplace_back(val);
            }

            // Check people who already forget
            if (!share.empty() && i - share[0].first == forget)
            {
                // Remove it from the list and update the shareCnt
                auto val{share.front()};
                share.pop_front();

                shrCnt = (shrCnt - val.second + MOD) % MOD;
            }

            // Then make all the people in the share list to share
            if (shrCnt != 0 && !share.empty())
            {
                knwCnt = (knwCnt + shrCnt) % MOD;

                // Push all the people in the know list also
                know.emplace_back(std::make_pair(i, shrCnt % MOD));
            }
        }
        return (knwCnt + shrCnt) % MOD;
    }
};
