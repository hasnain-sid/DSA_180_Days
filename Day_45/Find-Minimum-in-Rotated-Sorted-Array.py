class Solution:
    def findMin(self, nums: List[int]) -> int:
        i = 0
        j = len(nums) - 1
        ans = nums[0]
        while i <= j:
            mid = (i + j) // 2
            ans = min(ans, nums[mid])
            # i = mid
            # if nums[mid] == target:
            #     return mid
            
            # Check if left half is sorted
            if nums[i] <= nums[mid]:
                # Target is in the sorted left half
                ans = min(ans,nums[i])
                # if nums[i] <= target < nums[mid]:
                #     j = mid - 1
                # else:
                i = mid + 1
            else:
                # Right half is sorted
                # Target is in the sorted right half
                # if nums[mid] < target <= nums[j]:
                #     i = mid + 1
                # else:
                j = mid - 1
        
        return ans
        