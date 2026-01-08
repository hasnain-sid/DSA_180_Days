1from collections import deque
2
3# Time complexity: O(rows * cols) -> each cell is visited at least once
4# Space complexity: O(rows * cols) -> in the worst case if all the oranges are rotten they will be added to the queue
5
6class Solution:
7    def orangesRotting(self, grid: List[List[int]]) -> int:
8        
9        # number of rows
10        rows = len(grid)
11        if rows == 0:  # check if grid is empty
12            return -1
13        
14        # number of columns
15        cols = len(grid[0])
16        
17        # keep track of fresh oranges
18        fresh_cnt = 0
19        
20        # queue with rotten oranges (for BFS)
21        rotten = deque()
22        
23        # visit each cell in the grid
24        for r in range(rows):
25            for c in range(cols):
26                if grid[r][c] == 2:
27                    # add the rotten orange coordinates to the queue
28                    rotten.append((r, c))
29                elif grid[r][c] == 1:
30                    # update fresh oranges count
31                    fresh_cnt += 1
32        
33        # keep track of minutes passed.
34        minutes_passed = 0
35        
36        # If there are rotten oranges in the queue and there are still fresh oranges in the grid keep looping
37        while rotten and fresh_cnt > 0:
38
39            # update the number of minutes passed
40            # it is safe to update the minutes by 1, since we visit oranges level by level in BFS traversal.
41            minutes_passed += 1
42            
43            # process rotten oranges on the current level
44            for _ in range(len(rotten)):
45                x, y = rotten.popleft()
46                
47                # visit all the adjacent cells
48                for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
49                    # calculate the coordinates of the adjacent cell
50                    xx, yy = x + dx, y + dy
51                    # ignore the cell if it is out of the grid boundary
52                    if xx < 0 or xx == rows or yy < 0 or yy == cols:
53                        continue
54                    # ignore the cell if it is empty '0' or visited before '2'
55                    if grid[xx][yy] == 0 or grid[xx][yy] == 2:
56                        continue
57                        
58                    # update the fresh oranges count
59                    fresh_cnt -= 1
60                    
61                    # mark the current fresh orange as rotten
62                    grid[xx][yy] = 2
63                    
64                    # add the current rotten to the queue
65                    rotten.append((xx, yy))
66
67        
68        # return the number of minutes taken to make all the fresh oranges to be rotten
69        # return -1 if there are fresh oranges left in the grid (there were no adjacent rotten oranges to make them rotten)
70        return minutes_passed if fresh_cnt == 0 else -1