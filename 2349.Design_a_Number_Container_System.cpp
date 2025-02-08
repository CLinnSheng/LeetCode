/*
 * Functions:
 * Insert or replace at the given index
 * Return the smallest number in the system
 *
 * If the index already have anumber replace it --> Hashmap
 *
 * */
#include <climits>
#include <set>
#include <unordered_map>
class NumberContainers
{
  private:
    // set is sorted ascendingly in cpp
    // so we just get the first object in the set which has the least index
    std::unordered_map<int, std::set<int>> num2index;
    std::unordered_map<int, int> index2num;

  public:
    NumberContainers()
    {
        num2index = std::unordered_map<int, std::set<int>>();
        index2num = std::unordered_map<int, int>();
    }

    void change(int index, int number)
    {
        // check whether this index has been assigned a number or not
        if (index2num.find(index) != index2num.end())
        {
            int prevNumber{index2num[index]};
            num2index[prevNumber].erase(index);
            if (num2index[prevNumber].empty())
                num2index.erase(prevNumber);
        }

        index2num[index] = number;
        num2index[number].insert(index);
    }

    int find(int number)
    {
        if (num2index.find(number) != num2index.end())
            return *(num2index[number].begin());
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
