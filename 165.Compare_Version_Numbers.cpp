#include <sstream>
#include <string>

/*
 * Goal: Compare version
 *
 * Intuition:
 * Just separate the version number into two parts, and compare them
 * Or just use 2pointer to compare
 * */
class Solution
{
  public:
    int compareVersion(std::string version1, std::string version2)
    {
        std::stringstream s1{version1}, s2{version2};
        std::string v1, v2;

        while (std::getline(s1, v1, '.') || std::getline(s2, v2, '.'))
        {
            int num1 = v1.empty() ? 0 : std::stoi(v1);
            int num2 = v2.empty() ? 0 : std::stoi(v2);

            if (num1 > num2)
                return -1;
            if (num1 < num2)
                return 1;

            v1.clear();
            v2.clear();
        }
        return 0;
    }
};
