class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.at(i).size(); j++)
            {
                if (board[i][j] != '.')
                {
                    // Horizontal
                    for(int k = 0; k < board.at(i).size(); k++)
                    {
                        if(k == j)
                            continue;

                        if(board[i][k] == board[i][j])
                            return false;
                    }

                    // Vertical
                    for(int k = 0; k < board.size(); k++)
                    {
                        if(k == i)
                            continue;

                        if(board[k][j] == board[i][j])
                            return false;
                    }

                    // Sub-box check
                    int startRow = (i / 3) * 3;
                    int startCol = (j / 3) * 3;

                    for (int k = startRow; k < startRow + 3; k++) {
                        for (int l = startCol; l < startCol + 3; l++) {
                            if (k == i && l == j) continue;
                            if (board[k][l] == board[i][j]) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};