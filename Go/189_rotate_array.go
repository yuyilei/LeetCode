/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。 
利用翻转，右移，左移都是一个套路，只有略微不同。。要先用取余来确定真正移动的步长 
但是Go居然没有内置的int的min函数。。
*/
func reverse(nums []int){
    for i, j := 0, len(nums)-1 ; i < j ; i, j = i+1, j-1 {
        nums[i], nums[j] = nums[j], nums[i] 
    }
} 

func rotate(nums []int, k int){
    k = k % len(nums); 
    reverse(nums[len(nums)-k:])
    reverse(nums[:len(nums)-k])
    reverse(nums[:])
} 
