class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()) ;
        this->t = target ; 
        c = candidates ; 
        getres(0,0) ; 
        return res ; 
    }
private: 
    int t ; 
    vector<int> c , tmp ; 
    vector<vector<int> > res ; 
    void getres(int pos , int sum ) {
        if ( sum == t ) {
            res.push_back(tmp) ; 
            return ; 
        }
        for ( int i = pos ; i < c.size() ; i++ ){ 
            if ( i == pos && ( sum > t && c[i] > 0 || sum < t && c[i] < 0 )) 
                return ; 
            if ( sum + c[i] > t ) 
                return ; 
            tmp.push_back(c[i]) ; 
            getres(i,sum+c[i]) ; 
            tmp.pop_back() ;
        }
    }
};