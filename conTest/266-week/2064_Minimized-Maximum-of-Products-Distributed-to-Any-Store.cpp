class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end()); 
        if (n == quantities.size()) {
            return quantities.back(); 
        }
        long sum = 0; 
        for (int q: quantities) 
            sum += q;
        long left = divide(sum, n); 
        long right = quantities.back(); 
        // 二分法
        while (left < right) {
            long mid = (left+right)/2;
            bool could = couldStore(quantities, n, mid); 
            if (could) 
                right = mid; 
            else 
                left = mid+1;
        }
        return left; 
    }
private: 
    // 判断x是否符合条件
    bool couldStore(vector<int>& quantities, int n, long x) {
        long cnt = 0; 
        for (int i = quantities.size() - 1; i >= 0; i--) {
            int cur = quantities[i]; 
            long tmp = divide(cur, x);
            cnt += tmp;
            if (cnt > n) 
                return false;
        }
        return true;
    }
    long divide(long a, long b) {
        long res = a / b; 
        if (a % b) 
            res++; 
        return res;
    }
};