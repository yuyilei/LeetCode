class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( i % 15 == 0 ) {
                res.push_back("FizzBuzz");
            }
            else if ( i % 3 == 0 ) {
                res.push_back("Fizz");
            }
            else if ( i % 5 == 0 ) {
                res.push_back("Buzz"); 
            }
            else {
                res.push_back(itoa(i));
                // itoa需要自己实现... 
                // 或 to_string(i)，不需要自己实现... 
            }
        }
        return res;
    }
    string itoa(int n) {
        string res = "";
        while ( n ) {
            char now = (n % 10) + '0';
            res = now + res;
            n /= 10;
        }
        return res;
    }
};