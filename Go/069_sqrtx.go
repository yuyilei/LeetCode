/*
方法一：
*/
func mySqrt(x int) int {
    for i := 0 ; i <= x ; i++ {
        tmp := i*i
        if tmp == x {
            return i 
        }
        if tmp > x {
            return i - 1 
        }
    }
    return 1
} 


/*
二分法:
go 没有while和 do while 
*/
func mySqrt(x int) int {
    left, right := 0, x 
    for {
        if left > right {
            break 
        }
        mid := (left + right)/2 
        tmp := mid*mid 
        if tmp == x {
            return mid 
        } else if tmp > x {
            right = mid - 1
        } else {
            left = mid + 1 
        }
    }
    return left - 1
}


/*
牛顿迭代法 
*/
func mySqrt(x int) int {
    res := x 
    for res*res > x {
        res = ( res + x/res ) / 2
    }
    return res
}