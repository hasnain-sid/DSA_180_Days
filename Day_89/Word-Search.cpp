class Solution {
public:
vector<vector<int>> visited;
bool helper(vector<vector<char>>& image, int i, int j,string &str,string &word)
    {
        // return false;
        
        int n = image.size();
        int m = image[0].size();
        if(i<0 || i==image.size() || j<0 || j==image[0].size())
        return false;

        if(str.size() == word.size())
        {
            // // // cout  << "hfefep";
            if(str == word)
            return true;
            return false;
        }
        visited[i][j] = 1;
        // return false;
        bool a1 = false;
        if(j > 0)
        {
            if(visited[i][j-1] == 0)
            {
                visited[i][j-1] = 1;
                str += image[i][j-1];
                a1 = helper(image,i,j-1,str,word);
                // // cout  << str << endl;
                visited[i][j-1] = 0;
                str.pop_back();
            }
        }
        bool a2 = false;
        if(i > 0)
        {
            if(visited[i-1][j] == 0)
            {
                visited[i-1][j] = 1;
                str += image[i-1][j];
                a2=helper(image,i-1,j,str,word);
                            // // cout  << str << endl;
                visited[i-1][j] = 0;
                str.pop_back();
            }
            // helper(image,i-1,j,str,word);

        }
        // helper(image,i,j-1,str,word);
        bool a3 = false;

        if(j < m-1 )
        {
            if(visited[i][j+1] == 0)
            {
                visited[i][j+1] = 1;
                str += image[i][j+1];
                a3=helper(image,i,j+1,str,word);
                            // // cout  << str << endl;
                visited[i][j+1] = 0;
                str.pop_back();
            }
        }
        // // helper(image,i,j+1,str,word);
        bool a4 = false;
        if(i < n-1)
        {
            if(visited[i+1][j] == 0)
            {
                visited[i+1][j] = 1;
                str += image[i+1][j];
                a4=helper(image,i+1,j,str,word);
                            // // cout  << str << endl;
                visited[i+1][j] = 0;
                str.pop_back();
            }
        }
        // helper(image,i+1,j,str,word);
        // if(str.size() == word.size())
        // {
        //     if(str == word)
            // return true;
            // return false;
        // }
        return (a1 or a2 or a3 or a4);
        // return a1;
        
    }
    bool check(vector<vector<char>>& board,int i,int j,char ch,string &word)
    {
        // if(i<0 || i==image.size() || j<0 || j==image[0].size() || image[i][j]!=oldColor)
        // return false;
        // return true;
        // string tmp = tmp + word[0] + ch;
       
        string tmp;
        tmp.push_back(word[0]);
        tmp.push_back(ch);
        int n = board[0].size();
        int m = board.size();
        if(j > 0)
        {
            if(board[i][j-1] == ch and visited[i][j-1] == 0)
            {
                // visited[i][j-1] = 1;
                if(helper(board,i,j-1,tmp,word))
                return true;
                visited[i][j-1] = 0;
            }
        }
        if(j < n-1)
        {
            if(board[i][j+1] == ch and visited[i][j+1] == 0)
            {
                // visited[i][j+1] = 1;
                if(helper(board,i,j+1,tmp,word))
                return true;
                visited[i][j+1] = 0 ;
                
            }
        }
        if(i > 0)
        {
            if(board[i-1][j] == ch and visited[i-1][j] == 0)
            {
                // visited[i-1][j] = 1;
                if(helper(board,i-1,j,tmp,word))
                return true;
                visited[i-1][j] = 0;
            }
        }
        if(i < m-1)
        {
            if(board[i+1][j] == ch and visited[i+1][j] == 0)
            {
                // visited[i+1][j] = 1;
                if(helper(board,i+1,j,tmp,word))
                return true;
                visited[i+1][j] = 0;
            }
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            vector<int> vec;
            
            for(int j = 0; j < board[0].size(); j++)
            {
                vec.push_back(0);
            }
            visited.push_back(vec);
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(word[0] == board[i][j])
                {
                    // // cout  << i << " " << j << "-<\n";
                    visited[i][j] = 1;
                    if(word.size() == 1)
                        return true;
                    if(check(board,i,j,word[1],word))
                    {
                        return true;
                    }
                    visited[i][j] = 0;
                }

            }
        }
        return false;
    }
};