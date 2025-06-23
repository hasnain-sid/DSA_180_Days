class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)

        # Find next smaller element indexes
        next_smaller = [n] * n
        stack = []
        for i in range(n):
            while stack and heights[i] < heights[stack[-1]]:
                next_smaller[stack.pop()] = i
            stack.append(i)

        # Find previous smaller element indexes
        prev_smaller = [-1] * n
        stack = []
        for i in range(n-1, -1, -1):  # Iterate backwards
            while stack and heights[i] < heights[stack[-1]]:
                prev_smaller[stack.pop()] = i
            stack.append(i)

        # Final area using both next and prev smaller
        max_area = 0
        for i in range(n):
            area = heights[i] * (next_smaller[i] - prev_smaller[i] - 1)
            max_area = max(max_area, area)

        return max_area
