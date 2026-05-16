#include <vector>
class MyCircularQueue
{
    // Design a queue such that it can make use of the spaces in front
    // insert new element when there is space in the front
    int capacity, front, back, size;
    std::vector<int> arr;

  public:
    MyCircularQueue(int k)
    {
        capacity = k;

        // Keep track of the current size of the queue
        size = 0;
        arr = std::vector<int>(k, -1);

        // Front & Back to keep track of the queue current first and last index
        front = 0;
        back = -1;
    }

    bool enQueue(int value)
    {
        // Check whether full or not
        if (isFull())
        {
            return false;
        }
        // Insert in the front if not full and has space
        back = (back + 1) % capacity;
        arr[back] = value;
        size++;
        return true;
    }

    bool deQueue()
    {
        // Check whether is it empty or not
        if (isEmpty())
        {
            return false;
        }
        // Pop from the front (queue)
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front()
    {
        // Check whether empty or not
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int Rear()
    {
        // Check whether empty or not
        if (isEmpty())
        {
            return -1;
        }
        return arr[back];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return capacity == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
