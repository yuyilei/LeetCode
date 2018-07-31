/*
原序列无序，要求时间复杂度为  O(n) 
利用map做哈希表，空间换取时间 
*/
func longestConsecutive(nums []int) int {
    help := make(map[int]bool) 
    res := 0
    for _, i := range nums {
        help[i] = true 
    }
    for _, i := range nums {
        tmp := 1 
        low, high := i - 1, i + 1  
        for ; help[low] ; low-- {
            tmp++
        }
        for ; help[high] ; high++ {
            tmp++
        }
        if tmp > res {
            res = tmp 
            for j := low ; j <= high ; j++ {
                help[j] = false;
            }
        }
    }
    return res
}