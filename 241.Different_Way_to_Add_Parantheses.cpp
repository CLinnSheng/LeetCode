
#include <vector>
#include <string>

/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
You may return the answer in any order.

Intuition: Recursively call the function everytime we met an operator and split into left and right part
eg: 2+3+1 --> 2+(3+1) / (2+3)+1

Constraint the number is in the range of [0, 99]
Time Complexity: O(n*2^n) at every operator we gonna split into two parts which leads to 2^n and we iterate through the expression so (n)
Space Complexity: O(2^n) due to the splitting at each split we create an array
*/

class Solution 
{
public:
    std::vector<int> diffWaysToCompute(std::string expression) 
    {
        // Base Case when we only left 1 number either single or double digts
        if (expression.length() == 2 || expression.length() == 1 ) return { stoi(expression) };
        
        std::vector<int> ans;

        // find the operator and split into two parts
        for (int i = 0; i < expression.size(); i++)
        {
            auto temp = expression[i];
            
            if (isdigit(temp)) continue;
            else
            {
                // split it
                std::vector<int> lefts = diffWaysToCompute(expression.substr(0, i));
                std::vector<int> rights = diffWaysToCompute(expression.substr(i + 1));
                
                // now try to compute the sum
                for (const auto& left : lefts)
                    for (const auto& right : rights)                     
                        switch (temp)
                        {
                            case '+': ans.emplace_back(left + right);
                            break;
                            case '-': ans.emplace_back(left + right);
                            break;
                            case '*':ans.emplace_back(left * right);
                            break;
                        }
                    
            }
        }
        return ans;
    }
};
