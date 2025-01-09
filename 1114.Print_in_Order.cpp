#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
using std::function;

/*
 * Call first function will print first and the same goes to first,second & third
 *
 * Goal: Design the system such that it is always print in this order firstsecondthird.
 * no matter whats the order of function call
 *
 * Intuition:
 * Use an atomic variable to store the count
 * we only let the thread in the second function to print only if the count is 2 and the same applies to third function
 * */
class Foo
{
  private:
    std::condition_variable cv;
    std::mutex m;
    int flag;

  public:
    Foo() : flag{1}
    {
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 2;
        // call all the thread that put to sleep
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        // try to accquire the lock first
        std::unique_lock<std::mutex> lock(m);
        // use a condition variable to determine whether want the thread to continue on this function or not
        // since this the 'second function', we only allow the thread to continue if the flag is set to 2
        cv.wait(lock, [this]() { return this->flag == 2; });
        // it will put the thread to sleep if it is false otherwise proceed

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this]() { return this->flag == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
