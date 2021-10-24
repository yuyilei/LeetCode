class Bank {
public:
    Bank(vector<long long>& in_balance) {
        // the name of parameter can not be the same as the local variable
        balance = in_balance; 
        size = balance.size(); 
        cout << size << endl;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > size || account2 > size) {
            return false;
        }
        if (balance[account1-1] < money) {
            return false;
        }
        balance[account1-1] -= money; 
        balance[account2-1] += money; 
        return true; 
    }
    
    bool deposit(int account, long long money) {
        if (account > size) {
            return false;
        }
        balance[account-1] += money; 
        return true; 
    }
    
    bool withdraw(int account, long long money) {
        if (account > size || balance[account-1] < money) {
            return false;
        }
        balance[account-1] -= money; 
        return true; 
    }
private: 
    vector<long long> balance; 
    int size; 
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */