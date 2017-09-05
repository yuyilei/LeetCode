// 解法一 ： 寻找塔顶，再从两边到塔顶，这样的话就只能上升 
class Solution {
public:
    int trap(vector<int>& height) {
        int i , max = 0 , tmp , res = 0 , len = height.size() ; 
        if ( !len )
            return 0 ; 
        for ( i = 0 ; i < len ; i++ ){
            max = ( height[max] > height[i]) ? max : i ; 
         }
        for ( i = 0 , tmp = height[0] ; i < max ; i++ ){
            tmp = ( tmp > height[i]) ? tmp : height[i] ; 
            res += ( tmp - height[i] ) ; 
        }
        for ( i = len - 1 , tmp = height[len-1] ; i > max  ; i--  ) {
            tmp = ( tmp > height[i]) ? tmp : height[i] ; 
            res += ( tmp - height[i] ) ; 
        }
        return res ; 
    }
};
// 解法二： 其实道理和解法一相似，但是没有显式的找出最高点，而是通过左右两点的不断移动得到最高点的 
// 保证移动的那个点是左右两点中的较低点，这样移动的时候遇到更低的点就能保证那是个凹型（就能相加）  
class Solution {
public:
    int trap(vector<int>& height) {
        int tmp , res = 0 , begin = 0 , end = height.size() - 1 ; 
        while ( begin <= end ){
            tmp = min(height[begin],height[end]) ; 
            if ( tmp == height[begin] ){    
                while ( ++begin < end && height[begin] < tmp ) 
                    res += ( tmp - height[begin]) ; 
            } 
            else {
                while ( begin < --end && height[end] < tmp )
                    res += ( tmp - height[end]) ; 
            }
        }
        return res ; 
    }
};