// 解法一： 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
        sort(candidates.begin(),candidates.end()) ; 
        cand = candidates ; 
        this->target = target ; 
        vector<vector<int> > res ; 
        vector<int> tmp ; 
        for ( int i = 0 ; i < candidates.size() ; i++ ) 
            getres(res,tmp,i,0) ;
        sort(res.begin(),res.end()) ; 
        res.erase(unique(res.begin(), res.end()), res.end()) ;
         //先用sort函数排序，然后unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器 再用erase函数擦除从这个元素到最后元素的所有的重复元素 
        return res ; 
    } 
private : 
    int target ; 
    vector<int> cand ; 
    void getres(vector<vector<int> > & res , vector<int> tmp , int pos , int sum ) {  
        sum += cand[pos] ;  
        tmp.push_back(cand[pos]) ; 
        if ( sum >= target ) { 
            if ( sum == target )
            res.push_back(tmp) ; 
            tmp.clear() ; 
            return ; 
        }
        for ( int i = pos + 1 ; i < cand.size() ; i++  )
            getres(res,tmp,i,sum) ; 
        tmp.pop_back() ;
    }
};


//  解法二 ： 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
        sort(candidates.begin(),candidates.end()) ; 
        cand = candidates ; 
        this->target = target ; 
        vector<vector<int> > res ; 
        vector<int> tmp ; 
        getres(res,tmp,0,0) ;
        return res ; 
    } 
private : 
    int target ; 
    vector<int> cand ; 
    void getres(vector<vector<int> > & res , vector<int> tmp , int pos , int sum ) {  
        if ( sum >= target ) {
            if ( sum == target ) 
                res.push_back(tmp) ; 
            return ; 
        }  
        for ( int i = pos ; i < cand.size() && cand[i] <= target  ; i++ ) {
            tmp.push_back(cand[i]) ; 
            getres(res,tmp,i+1,sum+cand[i]) ; // 这里用sum+cand[i] 作为参数传入更好一点，如果sum+=cand[i]会改变sum的值，之后还要减去cand[i] 
            tmp.pop_back() ; 
            while ( i < cand.size() - 1 && cand[i] == cand[i+1] ) i++ ; // 去除重复 
        }
    }
};