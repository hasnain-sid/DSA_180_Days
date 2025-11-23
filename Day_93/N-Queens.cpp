class Solution {
public:

int cb[10][10];
vector<vector<string>> ans;
bool is_possible(int n, int row, int col)
{
  for (int i = row - 1; i >= 0; i--)
  {
    if (cb[i][col] == 1)
    {
      return false; 
    }
    
  }
  for (int i = row - 1,j = col - 1; i >= 0 and j >= 0; i--,j--)
  {
    if (cb[i][j] == 1)
    {
      return false; 
    }
  }
  for (int i = row - 1,j = col + 1; i >= 0 and j < n; i--,j++)
  {
    if (cb[i][j] == 1)
    {
      return false; 
    }
  }
  return true;
  
  
}
void n_queen_helper(int n, int row)
{
  if (row == n)
  {
      vector<string> v;
    for (int i = 0; i < n; i++)
    {
        
        string vec;
      for (int j = 0; j < n; j++)
      {
        // cout << cb[i][j] << " ";
        if(cb[i][j] == 1)
        vec.push_back('Q');
        else
        vec.push_back('.');
      } 
      v.push_back(vec);
        
    //   cout << endl;
    }
    ans.push_back(v);
    // cout << endl;
    return;
    
  }
  for (int i = 0; i < n; i++)
  {
    if (is_possible(n,row,i))
    {
      cb[row][i] = 1;
      n_queen_helper(n,row+1);
      cb[row][i] = 0;
    }
  }
  return;

  
  
}
void place_queen(int n)
{
  memset(cb, 0, sizeof(int));
  
  n_queen_helper(n,0);
}

    vector<vector<string>> solveNQueens(int n) {
        place_queen(n);
        return ans;
        
        
    }
};