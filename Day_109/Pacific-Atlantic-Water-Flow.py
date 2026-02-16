1from collections import deque
2from typing import List, Set, Tuple
3
4class Solution:
5    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
6        if not heights or not heights[0]:
7            return []
8
9        rows, cols = len(heights), len(heights[0])
10
11        def bfs(starts: list[Tuple[int, int]]) -> Set[Tuple[int, int]]:
12            q = deque(starts)          # multi-source queue
13            visited = set(starts)      # mark all sources visited
14
15            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
16
17            while q:
18                r, c = q.popleft()
19
20                for dr, dc in directions:
21                    nr, nc = r + dr, c + dc
22
23                    # inside grid?
24                    if 0 <= nr < rows and 0 <= nc < cols:
25                        # reverse flow condition: next height >= current height
26                        if (nr, nc) not in visited and heights[nr][nc] >= heights[r][c]:
27                            visited.add((nr, nc))
28                            q.append((nr, nc))
29
30            return visited
31
32        # Pacific sources: top row + left col
33        pacific_starts = [(0, c) for c in range(cols)] + [(r, 0) for r in range(rows)]
34
35        # Atlantic sources: bottom row + right col
36        atlantic_starts = [(rows - 1, c) for c in range(cols)] + [(r, cols - 1) for r in range(rows)]
37
38        pacific_reachable = bfs(pacific_starts)
39        atlantic_reachable = bfs(atlantic_starts)
40
41        # intersection
42        ans = []
43        for r in range(rows):
44            for c in range(cols):
45                if (r, c) in pacific_reachable and (r, c) in atlantic_reachable:
46                    ans.append([r, c])
47
48        return ans