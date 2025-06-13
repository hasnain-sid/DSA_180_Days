class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i = 0
        j = len(nums) - 1
        
        while i <= j:
            mid = (i + j) // 2
            
            if nums[mid] == target:
                return mid
            
            # Check if left half is sorted
            if nums[i] <= nums[mid]:
                # Target is in the sorted left half
                if nums[i] <= target < nums[mid]:
                    j = mid - 1
                else:
                    i = mid + 1
            else:
                # Right half is sorted
                # Target is in the sorted right half
                if nums[mid] < target <= nums[j]:
                    i = mid + 1
                else:
                    j = mid - 1
        
        return -1