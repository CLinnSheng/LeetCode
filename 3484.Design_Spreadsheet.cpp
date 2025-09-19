#include <string>
#include <unordered_map>
using std::string;

class Spreadsheet
{
  public:
    std::unordered_map<string, int> cells;
    Spreadsheet(int rows)
    {
    }

    void setCell(string cell, int value)
    {
        cells[cell] = value;
    }

    void resetCell(string cell)
    {
        cells.erase(cell);
    }

    int getValue(string formula)
    {
        // Remove '='
        string equation = formula.substr(1);

        for (int i{}; i < equation.length(); i++)
        {
            // Keep looping until found '+'
            if (equation[i] == '+')
            {
                string op1 = equation.substr(0, i);
                string op2 = equation.substr(i + 1);

                // Now check whether the cells have value or not
                int val1 = op1[0] >= 'A' && op1[0] <= 'Z' ? cells[op1] : std::stoi(op1);
                int val2 = op2[0] >= 'A' && op2[0] <= 'Z' ? cells[op2] : std::stoi(op2);

                return val1 + val2;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
