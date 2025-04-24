#include <cstring>
#include <vector>

/*
 * Design a hashset
 *
 * Constraint:
 * 0 <= key <= 6
 *
 * Intuition: Can use an array to cover all possible keys
 *
 * */
class MyHashSet
{
  private:
    std::vector<bool> arrays;

  public:
    MyHashSet()
    {
        arrays.resize(1e6 + 1, false);
    }

    void add(int key)
    {
        arrays[key] = true;
    }

    void remove(int key)
    {
        arrays[key] = false;
    }

    bool contains(int key)
    {
        return arrays[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
