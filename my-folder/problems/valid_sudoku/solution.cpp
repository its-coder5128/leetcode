class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col)
    {
        int x = (row/3) * 3;
        int y = (col/3) * 3;

        for(int i = 0;i<9;i++)
        {
            if(i != row && board[i][col] == board[row][col])
                return false;
            if(i != col && board[row][i] == board[row][col])
                return false;
            if((x + i/3) != row && (y + i%3) != col && board[x + i/3][y + i%3] == board[row][col])
                return false;
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(!isSafe(board,i,j))
                        return false;
                }
            }
        }

        return true;
        
    }
};