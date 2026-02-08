1class Solution {
2public:
3    int numIslands(vector<vector<char>>& grid) {
4        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
5        for (int i = 0; i < m; i++) {
6            for (int j = 0; j < n; j++) {
7                if (grid[i][j] == '1') {
8                    islands++;
9                    eraseIslands(grid, i, j);
10                }
11            }
12        }
13        return islands;
14    }
15private:
16    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
17        int m = grid.size(), n = grid[0].size();
18        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
19            return;
20        }
21        grid[i][j] = '0';
22        eraseIslands(grid, i - 1, j);
23        eraseIslands(grid, i + 1, j);
24        eraseIslands(grid, i, j - 1);
25        eraseIslands(grid, i, j + 1);
26    }
27};