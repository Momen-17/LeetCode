class Solution(object):
    def twoSum(self, nums, target):
        hashmap = dict()
        for i in range(len(nums)):
            if target - nums[i] in hashmap:
                return [hashmap[target - nums[i]], i]
            hashmap[nums[i]] = i