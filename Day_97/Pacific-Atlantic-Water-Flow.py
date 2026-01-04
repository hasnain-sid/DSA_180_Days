1class Solution:
2    def helper(self, i, j, heights, ans_matrix, visited):
3        # Check bounds and if already visited
4        if (i < 0 or j < 0 or i >= len(heights) or j >= len(heights[0]) or visited[i][j]):
5            return
6        
7        # Mark as visited and increment count
8        visited[i][j] = True
9        ans_matrix[i][j] += 1
10        
11        # Explore all 4 directions - only go to cells with height >= current (water can flow from higher to lower)
12        if i + 1 < len(heights) and heights[i + 1][j] >= heights[i][j]:
13            self.helper(i + 1, j, heights, ans_matrix, visited)
14        if j + 1 < len(heights[0]) and heights[i][j + 1] >= heights[i][j]:
15            self.helper(i, j + 1, heights, ans_matrix, visited)
16        if i - 1 >= 0 and heights[i - 1][j] >= heights[i][j]:
17            self.helper(i - 1, j, heights, ans_matrix, visited)
18        if j - 1 >= 0 and heights[i][j - 1] >= heights[i][j]:
19            self.helper(i, j - 1, heights, ans_matrix, visited)
20
21    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
22        if not heights or not heights[0]:
23            return []
24        
25        rows = len(heights)
26        cols = len(heights[0])
27        ans_matrix = [[0] * cols for _ in range(rows)]
28
29        # DFS on first col (Pacific)
30        visited = [[False] * cols for _ in range(rows)]
31        for i in range(rows):
32            self.helper(i, 0, heights, ans_matrix, visited)
33        
34        # print(ans_matrix)
35        # DFS on first row (Pacific)
36        # visited = [[False] * cols for _ in range(rows)]
37        for j in range(cols):
38            self.helper(0, j, heights, ans_matrix, visited)
39
40        # print(ans_matrix)
41        # DFS on last col (Atlantic)
42        visited = [[False] * cols for _ in range(rows)]
43        for i in range(rows):
44            self.helper(i, cols - 1, heights, ans_matrix, visited)
45        # print(ans_matrix)
46        # DFS on last row (Atlantic)
47        # visited = [[False] * cols for _ in range(rows)]
48        for j in range(cols):
49            self.helper(rows - 1, j, heights, ans_matrix, visited)
50        # print(ans_matrix)
51        # Collect cells that can reach both oceans (count == 2)
52        result = []
53        for i in range(rows):
54            for j in range(cols):
55                if ans_matrix[i][j] >= 2:
56                    result.append([i, j])
57        
58        return result