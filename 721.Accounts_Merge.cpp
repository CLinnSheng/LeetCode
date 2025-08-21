#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector, std::string;

/*
 * accounts[i] is a list of string where accounts[i][0] is name and the rest of the elements are emails
 * Merge the accounts. 2 accounts definitely belongs to the same person if there is some common email to both accounts.
 * NOTE: Same name but belong to different people as people could have the same name.
 * Goal: After merging it, return the list of name with the emails in sorted order.
 *
 * Intuition:
 * 2 accounts belong to the same person if there is some common email to both accounts.
 * So from the list of emails if have common email then whole list of email belong to the same person as well
 * Since the question is mention about "merge" this give hint about using union find.
 * We can basically just union all the email in multiple account.
 *
 * Time COmplexity: At worst will be O(E * N lg E)
 * */

class UnionFind
{
  private:
    vector<int> parents, ranks;

  public:
    UnionFind(int n)
    {
        parents.resize(n);
        for (int i{}; i < n; i++)
            parents[i] = i;

        ranks.resize(n, 1);
    }

    int findParent(int x)
    {
        if (parents[x] != x)
            parents[x] = findParent(parents[parents[x]]);

        return parents[x];
    }

    bool unionSet(int x1, int x2)
    {
        int parent1{findParent(x1)}, parent2{findParent(x2)};

        if (parent1 == parent2)
            return false;

        if (ranks[parent1] > ranks[parent2])
        {
            parents[parent2] = parent1;
            ranks[parent1] += ranks[parent2];
        }
        else
        {
            parents[parent1] = parent2;
            ranks[parent2] += ranks[parent1];
        }

        return true;
    }
};
class Solution
{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n(accounts.size());
        UnionFind unionFind{n};

        // Hash map to store all emails
        // can use to track identical email
        std::unordered_map<string, int> emailToAcc;

        // O(E) --> E is the total amt of emails
        for (int i{}; i < n; i++)
        {
            for (int j{1}; j < accounts[i].size(); j++)
            {
                const string &email{accounts[i][j]};

                // Means we saw this account before, then they should belong to the same person
                if (emailToAcc.find(email) != emailToAcc.end())
                {
                    unionFind.unionSet(i, emailToAcc[email]);
                }
                else
                {
                    emailToAcc[email] = i;
                }
            }
        }

        // Group email by all the available name
        std::unordered_map<int, vector<string>> emailGroup;
        for (const auto &[email, accId] : emailToAcc)
        {
            int leader{unionFind.findParent(accId)};
            emailGroup[leader].emplace_back(email);
        }

        vector<vector<string>> answer;
        for (auto &[accId, emails] : emailGroup)
        {
            // O(ElgE)
            std::sort(emails.begin(), emails.end());

            vector<string> substring;
            substring.emplace_back(accounts[accId][0]);
            substring.insert(substring.end(), emails.begin(), emails.end());

            answer.emplace_back(substring);
        }

        return answer;
    }
};
