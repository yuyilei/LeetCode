/*
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
注意：
1. 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
2. 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
3. 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
*/


/*
一、暴力枚举法：
*/
class Solution {
public:
    bool judgePoint24(vector<int>& nums){
        sort(nums.begin(),nums.end());                          // 先进行排序，再获取全排序，如果不先排序，获取的排列是不全的 
        do{
            if ( judgevalid(nums) ) 
                return true;
        } while ( next_permutation(nums.begin(),nums.end()) );    // 获取下一个排列
        return false;
    }
    bool judgevalid(vector<int> &nums){
        double m = nums[0], n = nums[1], p = nums[2], q = nums[3];
        if ( judgevalid(m+n,p,q) || judgevalid(m-n,p,q) || judgevalid(m*n,p,q) || n != 0 && judgevalid(m/n,p,q) ) 
            return true;
        if ( judgevalid(m,n+p,q) || judgevalid(m,n-p,q) || judgevalid(m,n*p,q) || p != 0 && judgevalid(m,n/p,q) ) 
            return true;
        if ( judgevalid(m,n,p+q) || judgevalid(m,n,p-q) || judgevalid(m,n,p*q) || q != 0 && judgevalid(m,n,p/q) ) 
            return true;
        return false;
    }
    bool judgevalid(double m, double n, double p){
        if ( judgevalid(m+n,p) || judgevalid(m-n,p) || judgevalid(m*n,p) || n != 0 && judgevalid(m/n,p) ) 
            return true;
        if ( judgevalid(m,n+p) || judgevalid(m,n-p) || judgevalid(m,n*p) || p != 0 && judgevalid(m,n/p) )
            return true;
        return false;
    }
    bool judgevalid(double m, double n){
        if ( abs(m+n-24.0) < 0.0001 || abs(m-n-24.0) < 0.0001 ||
             abs(m*n-24.0) < 0.0001 || n != 0 && abs(m/n-24.0) < 0.0001)
            return true;
        return false;
    }
};


/*
二、回溯法？
*/
class Solution {
public:
    bool judgePoint24(vector<int>& nums){
        vector<double> doublenums;
        for ( int tmp : nums )
            doublenums.push_back((double)tmp);
        return BackTracking(doublenums);   
    }
    bool BackTracking(vector<double>& nums){
        if ( nums.empty() )
            return false;
        if ( nums.size() == 1 )
            return ( abs(nums[0] - 24.0 ) < 0.0001 );
        int s = nums.size();
        for ( int i = 0 ; i < s ; i++ ){
            for ( int j = 0 ; j < s ; j++ ){
                if ( i == j )
                    continue;
                vector<double> tmps;
                for ( int p = 0 ; p < s ; p++ ){
                    if ( p != i && p != j )
                        tmps.push_back(nums[p]);
                }
                for ( int p = 0 ; p < 4 ; p++ ){
                    // +与* 是前后可逆的，只用算一次   || 除数是0的情况要跳过  
                    if ( ( p < 2 && j < i ) || ( p == 3 && nums[j] == 0 ) ) 
                        continue;
                    switch ( p ){
                        case 0 : tmps.push_back(nums[i]*nums[j]);
                                 break;
                        case 1 : tmps.push_back(nums[i]+nums[j]);
                                 break;
                        case 2 : tmps.push_back(nums[i]-nums[j]);
                                 break;
                        case 3 : tmps.push_back(nums[i]/nums[j]);
                    }
                    if (BackTracking(tmps))
                        return true;
                    tmps.pop_back();
                }
            }
        }
        return false;
    }
};