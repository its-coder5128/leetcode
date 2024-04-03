class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int row,int col,int index)
    {
        if(index == word.size())
            return true;
        if(row >= board.size() || col >= board[0].size() || board[row][col] != word[index] || board[row][col] == '.')
            return false;
        char c = board[row][col];
        board[row][col] = '.';

        bool right = solve(board,word,row,col+1,index+1);
        bool left = solve(board,word,row,col-1,index+1);
        bool down = solve(board,word,row+1,col,index+1);
        bool up = solve(board,word,row-1,col,index+1);

        board[row][col] = c;

        return left || right || up || down;
    }
    bool exist(vector<vector<char>>& board, string word) {


        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(solve(board,word,i,j,0))
                    return true;
            }
        }

        return false;
    }
};