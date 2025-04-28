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
