class Solution {
public:
    bool isSafe(char c,vector<vector<char>>& board,int i,int j)
    {
        for(int k = 0;k<9;k++)
        {
            if(board[i][k]==c)
                return false;
            if(board[k][j]==c)
                return false;
            if(board[3*(i/3) + (k/3)][3*(j/3) + (k%3)] == c)
                return false;  
        }

        return true;
    }
    bool solveSudoku1(vector<vector<char>>& board)
    {
            for(int i=0 ;i <9;i++)
            {
                for(int j = 0;j<9;j++)
                {
                    if(board[i][j] == '.')
                    {
                        for(int k = 1;k<=9;k++)
                        {
                            if(isSafe('0' + k , board , i,j))
                            {
                                board[i][j] = '0' + k;
                                if(solveSudoku1(board))
                                    return true;

                                board[i][j] = '.' ;
                                
                            }
                        }
                        return false;
                    }
                }
            }

            return true;
    }
    void solveSudoku(vector<vector<char>>& board) {  
  
        bool flag = solveSudoku1(board);
            
    }
};