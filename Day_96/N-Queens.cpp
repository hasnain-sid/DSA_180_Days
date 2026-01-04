1class Solution {
2public:
3
4int cb[10][10];
5vector<vector<string>> ans;
6bool is_possible(int n, int row, int col)
7{
8  for (int i = row - 1; i >= 0; i--)
9  {
10    if (cb[i][col] == 1)
11    {
12      return false; 
13    }
14    
15  }
16  for (int i = row - 1,j = col - 1; i >= 0 and j >= 0; i--,j--)
17  {
18    if (cb[i][j] == 1)
19    {
20      return false; 
21    }
22  }
23  for (int i = row - 1,j = col + 1; i >= 0 and j < n; i--,j++)
24  {
25    if (cb[i][j] == 1)
26    {
27      return false; 
28    }
29  }
30  return true;
31  
32  
33}
34void n_queen_helper(int n, int row)
35{
36  if (row == n)
37  {
38      vector<string> v;
39    for (int i = 0; i < n; i++)
40    {
41        
42        string vec;
43      for (int j = 0; j < n; j++)
44      {
45        // cout << cb[i][j] << " ";
46        if(cb[i][j] == 1)
47        vec.push_back('Q');
48        else
49        vec.push_back('.');
50      } 
51      v.push_back(vec);
52        
53    //   cout << endl;
54    }
55    ans.push_back(v);
56    // cout << endl;
57    return;
58    
59  }
60  for (int i = 0; i < n; i++)
61  {
62    if (is_possible(n,row,i))
63    {
64      cb[row][i] = 1;
65      n_queen_helper(n,row+1);
66      cb[row][i] = 0;
67    }
68  }
69  return;
70
71  
72  
73}
74void place_queen(int n)
75{
76  memset(cb, 0, sizeof(int));
77  
78  n_queen_helper(n,0);
79}
80
81    vector<vector<string>> solveNQueens(int n) {
82        place_queen(n);
83        return ans;
84        
85        
86    }
87};