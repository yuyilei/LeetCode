// 解法一，简单粗暴，从每一个点往后遍历，寻找最大值，时间复杂度为o(n*n),最后一个测试样例超时
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i , res = 0 , l = height.size() , j , tmp , tmp_max , lower ;
        int *pb = new int [l] ; 
        for ( i = 0 ; i < l ; i++ ) {
            for ( j = i + 1 , tmp_max = 0 ; j < l ; j++ ) {
                lower = ( height[i] < height[j] ) ? height[i] : height[j] ; 
                tmp = lower*(j-i) ; 
                tmp_max = ( tmp_max > tmp ) ? tmp_max : tmp ; 
            }
            pb[i] = tmp_max ; 
        }
        sort(pb,pb+l-1) ; 
        return pb[l-2] ; 
    }
};

// 解法二 ： 从两边到中间
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 , right = height.size() - 1 , i , tmp , maxx ;
        for ( maxx = 0 ; left < right ; ) {
            tmp = min(height[left],height[right])*(right - left) ; 
            maxx = max(maxx,tmp) ;  
            if ( height[left]  <  height[right] )  // 保留两者中的较大值，较小值移动  
                left++ ; 
            else 
                right-- ; 
        }
        return maxx ; 
    }
};