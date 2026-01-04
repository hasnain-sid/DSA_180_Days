1from collections import deque
2
3class Solution:
4    def solve(self, board: List[List[str]]) -> None:
5        """
6        Do not return anything, modify board in-place instead.
7        """
8        
9        o = "O"
10        
11        n = len(board) 
12        m = len(board[0])
13
14        Q = deque()
15        
16        for i in range(n):
17            if board[i][0] == o:
18                Q.append((i,0))
19            if board[i][m-1] == o:
20                Q.append((i, m-1))
21                
22        for j in range(m):
23            if board[0][j] == o:
24                Q.append((0,j))
25            if board[n-1][j] == o:
26                Q.append((n-1, j))
27                
28        def inBounds(i,j):
29            return (0 <= i < n) and (0 <= j < m)
30                
31        while Q:
32            i,j = Q.popleft()
33            board[i][j] = "#"
34            
35            for ii, jj in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
36                if not inBounds(ii, jj):
37                    continue
38                if board[ii][jj] != o:
39                    continue
40                Q.append((ii,jj))
41                board[ii][jj] = '#'
42            
43        for i in range(n):
44            for j in range(m):
45                if board[i][j] == o:
46                    board[i][j] = 'X'
47                elif board[i][j] == '#':
48                    board[i][j] = o