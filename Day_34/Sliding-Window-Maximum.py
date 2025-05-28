from sortedcontainers import SortedDict
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        mp = SortedDict()
        i = j = 0
        ans = []

        while j < len(nums):  # Corrected loop condition
            value = nums[j]
            if value in mp:
                mp[value] += 1  # Simplified increment
            else:
                mp[value] = 1

            if j - i + 1 == k:  # Check if window size is reached
                ans.append(mp.keys()[-1])  # Access last key correctly
                # Slide the window
                mp[nums[i]] -= 1
                if mp[nums[i]] == 0:
                    del mp[nums[i]]
                i += 1
            j += 1
            # print(mp)

        return ans
        