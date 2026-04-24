1class Solution:
2    def twoSum(self, nums: List[int], target: int) -> List[int]:
3        ind_dict = {}
4        
5        for ind in range(len(nums)):
6            required_value = target - nums[ind]
7
8            if required_value in ind_dict and ind_dict[required_value] != ind:
9                return [ind_dict[required_value], ind]
10            
11            ind_dict[nums[ind]] = ind
12