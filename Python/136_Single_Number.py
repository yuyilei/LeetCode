# 解法一 ： 
class Solution(object):
    def singleNumber(self, nums):
        res = 0 
        for num in nums :
            res ^= num 
        return res 
# A ^ A = 0 , A ^ 0 = A 

# 解法二
class Solution(object):
    def singleNumber(self, nums): 
        nums.sort() 
        index = 0 
        while index < len(nums) - 1 :
            if nums[index] != nums[index+1] : 
                return nums[index] 
            index += 2 
        return nums[-1] 