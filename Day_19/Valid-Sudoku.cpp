class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;

        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++){
                if(st.find(board[i][j]) != st.end())
                    return false;
                
                else if (board[i][j]=='.'){
                    continue;
                }
                st.insert(board[i][j]);
            }
            st.clear();
        }

        for (int i = 0; i < 9; i++) {
            st.clear();
            for (int j=0 ; j<9; j++){
                if(st.find(board[j][i]) != st.end())
                    return false;
                else if (board[j][i]=='.'){
                    continue;
                }
                st.insert(board[j][i]);
            }
        }
        
        for(int k=0;k<9 ;k=k+3){
            for(int i=0;i<9 ;i=i+3){
                st.clear();
                for(int x=k;x<k+3;x++){
                    for(int z=i;z<i+3;z++){
                       
                        if(st.find(board[x][z]) != st.end()){
                            
                            return false;
                            
                          }
                        else if (board[x][z]=='.'){
                            continue;
                        }
                        st.insert(board[x][z]);
                    }
                }

        }
        }
    

        return true;



    }
};