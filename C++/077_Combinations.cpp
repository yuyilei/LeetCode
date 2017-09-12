class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k ;
        getres(0) ;
        return res ;
    }
private:
    int n, k ;
    vector<vector<int> > res ;
    vector<int> tmp ;
    void getres(int now ) {
        if ( tmp.size() == k) {
            res.push_back(tmp) ;
            return ;
        }
        for (int i = now + 1 ; i <= n ; i++) {
            tmp.push_back(i) ;
            getres(i) ;
            tmp.pop_back() ;
        }
    }
};

