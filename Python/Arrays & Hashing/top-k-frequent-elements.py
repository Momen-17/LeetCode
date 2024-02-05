class Solution(object):
    def topKFrequent(self, nums, k):
        nums_count = dict()
        for num in nums:
            nums_count[num] = nums_count.get(num, 0) + 1
        
        ret = sorted(nums_count.items(), key=lambda item: item[1], reverse=True)[:k]
        return [x[0] for x in ret[:k]]
