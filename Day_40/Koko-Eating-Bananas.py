import math
from typing import List

class Solution:
    def check(self, piles: List[int], mid: int, h: int) -> bool:
        used = 0
        for i in piles:
            used += math.ceil(i / mid)
        return used <= h

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        i = 1
        j = max(piles)
        ans = j

        while i <= j:
            mid = (i + j) // 2
            if self.check(piles, mid, h):
                ans = mid
                j = mid - 1
            else:
                i = mid + 1

        return ans
