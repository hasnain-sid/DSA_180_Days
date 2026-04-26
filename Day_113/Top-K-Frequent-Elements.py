1import heapq
2from collections import Counter
3from typing import List
4
5class Solution:
6    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
7        # Step 1: Count frequencies
8        # nums = [1,1,1,2,2,3], k = 2
9        # freq = {1: 3, 2: 2, 3: 1}
10        freq = Counter(nums)
11
12        # Step 2: Use a MIN-heap of size K
13        # We store (frequency, number) — heap compares by frequency (first element)
14        heap = []
15
16        for num, count in freq.items():
17            heapq.heappush(heap, (count, num))   # push current element
18
19            # Step 3: If heap exceeds K, remove the LEAST frequent
20            # This ensures only TOP K frequent stay in heap
21            if len(heap) > k:
22                heapq.heappop(heap)  # pops smallest frequency
23
24        # Step 4: Extract numbers from heap
25        return [num for count, num in heap]