class Solution:
    def twoSum(self, nums, target):
        for i , item in enumerate(nums) :
            temp = target - item
            if nums.count(temp) != 0 :
                j = nums.index(temp)
                if i != j :
                    res = []
                    res.append(i)
                    res.append(j)
                    return res
