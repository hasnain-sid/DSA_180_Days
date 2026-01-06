1class Solution:
2    def helper(self, board, i, j):
3        if i >= len(board) or j < 0 or i < 0 or j >= len(board[0]) or  board[i][j] == 'L' or board[i][j] == 'X':
4            return
5        if board[i][j] == 'O':
6            board[i][j] = 'L'
7        self.helper(board, i+1, j)
8        self.helper(board, i-1, j)
9        self.helper(board, i, j+1)
10        self.helper(board, i, j-1)
11       
12    def solve(self, board: List[List[str]]) -> None:
13        """
14        Do not return anything, modify board in-place instead.
15        """
16        m, n = len(board), len(board[0])
17        for i in range(m):
18            for j in [0, n-1]:
19                if board[i][j] == 'O':
20                    self.helper(board, i, j)
21        for j in range(n):
22            for i in [0, m-1]:
23                if board[i][j] == 'O':
24                    self.helper(board, i, j)
25        
26        for i in range(m):
27            for j in range(n):
28                if board[i][j] == 'O':
29                    board[i][j] = 'X'
30                elif board[i][j] == 'L':
31                    board[i][j] = 'O'