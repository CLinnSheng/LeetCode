#include <vector>
using std::vector;
/*
 * Automate all incoming transaction.
 * n accounts. Initial balance is stored in the balance array
 * */
class Bank
{
  private:
    vector<long long> accounts;

  public:
    Bank(vector<long long> &balance)
    {
        accounts = std::move(balance);
    }

    /*
     * Transfer money from account1 to account2.
     * Return true if successful
     * */
    bool transfer(int account1, int account2, long long money)
    {
        if (account1 < 1 || account2 < 1 || account1 > accounts.size() || account2 > accounts.size())
        {
            return false;
        }

        if (accounts[account1 - 1] < money)
        {
            return false;
        }
        accounts[account1 - 1] -= money;
        accounts[account2 - 1] += money;

        return true;
    }

    /*
     * Deposit money to account.
     * */
    bool deposit(int account, long long money)
    {
        if (account < 1 || account > accounts.size())
        {
            return false;
        }

        accounts[account - 1] += money;
        return true;
    }

    /*
     * Withdraw money from account.
     * */
    bool withdraw(int account, long long money)
    {
        if (account < 1 || account > accounts.size())
        {
            return false;
        }

        if (accounts[account - 1] < money)
        {
            return false;
        }
        accounts[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
