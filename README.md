# DSA_180_Days

1. 442 Optimization part is good.

# Subarray Sum Equals K - Understanding the Logic

## Key Insight

**Statement**: If the value `(currentSum - k)` exists in our hash map, it means we've found one or more subarrays ending at the current position that sum to exactly `k`.

**Explanation**:
* At any index `i`, `currentSum` represents the sum of all elements from index `0` to `i`
* If there was a previous position `j` where the prefix sum was `(currentSum - k)`, then the sum of elements from position `j+1` to `i` must be exactly `k`

## Example

Consider the array `[3, 4, 7, 2, -3, 1, 4, 2]` with `k = 7`

When we reach index 2 (element 7):
* `currentSum = 3 + 4 + 7 = 14`
* We check if `(currentSum - k) = 14 - 7 = 7` exists in our hash map
* If it does, it means there was a position where the prefix sum was 7
* The elements between that position and the current position sum to 7

This approach works because if the difference between two prefix sums equals `k`, then the subarray between those positions has a sum of `k`.

# Merge Sorted Arrays

## Key Insight
**Core Idea**: Merge from the end using 3 pointers to avoid overwriting unprocessed elements.

## Why It Works
* `nums1` has extra space (size m+n)
* Compare last elements first → place larger one at end
* No element overwriting since we work backwards

## Pointers
* `p1`: last element in nums1 (m-1)
* `p2`: last element in nums2 (n-1)
* `p`: insertion point (m+n-1)

## Example
```
nums1 = [1,3,5,0,0,0], m=3  
nums2 = [2,4,6], n=3
```

1. Compare 5 & 6 → place 6
2. Compare 5 & 4 → place 5
3. Compare 3 & 4 → place 4
4. Final: [1,2,3,4,5,6]

## Complexity
* **Time**: O(m+n)
* **Space**: O(1)

## Edge Cases
* `nums2` empty → done
* `nums1` empty → copy `nums2`
