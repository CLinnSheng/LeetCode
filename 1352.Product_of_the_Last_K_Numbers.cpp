/*
 * Needed to append the integer can either use stack, dqeue, queue or vector
 * But we needed to access the last k element.
 * What we can do is just keep track of the size and then extract it
 *
 * A more clever way to do this is isntead of jsut storing the element, why dont we straight away store its product from
 * 0 to n, and then when we want to find out the product of last k number, we just simply take product[k] and then
 * divided by product[n - k]
 * */
#include <vector>
class ProductOfNumbers
{
  private:
    std::vector<int> container;
    int size;

  public:
    ProductOfNumbers() : size{0}
    {
        container.emplace_back(1);
    }

    // Append the integer num to the stream
    void add(int num)
    {
        // handling when num is 0
        // because we cannot simply just push 0 into it as we cannot divieded by 0
        if (num == 0)
        {
            // restart the container as we only interested in the last k element
            // so all the previous elmeent is useless
            container = {1};
            size = 0;
        }
        else
        {
            container.emplace_back(num * container[size]);
            size++;
        }
    }

    // Return the product of the last k numbers in the current list
    // O(k)
    int getProduct(int k)
    {
        // handle when the contianer is reset
        if (k > size)
            return 0;
        // need to handle special cases where the product is 0
        return container[size] / container[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
