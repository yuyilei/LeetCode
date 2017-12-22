// 方法一： 
class Solution {
public:
    bool isHappy(int n) {
        set<int> help ; 
        return helper(n,help) ; 
    } 
    bool helper(int n, set<int> &help) {
        if ( n == 1 ) 
            return true ; 
        int res = 0 ; 
        while ( n > 0 ) {
            int tmp = n % 10 ; 
            res += tmp*tmp ; 
            n /= 10 ; 
        } 
        if ( help.find(res) != help.end() ) 
            return false ;
        help.insert(res) ; 
        return helper(res,help) ; 
    }
};



// 方法二： 
class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n ; 
        do {
            fast = helper(fast) ; 
            fast = helper(fast) ; 
            slow = helper(slow) ; 
        } while ( slow != fast ) ;
        return  slow == 1 ; 
    } 
    int helper(int n) {
        int res = 0 ; 
        while ( n > 0 ) {
            int tmp = n % 10 ; 
            res += tmp*tmp ; 
            n /= 10 ; 
        } 
        return res ; 
    }
};

// 出现循环的情况，可以使用快慢指针，如果，循环，最终快慢指针的结果最终会相同 