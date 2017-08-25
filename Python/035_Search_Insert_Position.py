class Solution(object):
    def searchInsert(self, nums, target):
        for i , item in enumerate(nums) :
            if item >= target :
                return i
        return len(nums)
