class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c)
    {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == '#')
            return;
        
        board[r][c] = '#';
        // cout<<r<<" "<<c<<" "<<board[r][c]<<endl;

        dfs(board,r,c-1);
        dfs(board,r-1,c);
        dfs(board,r,c+1);
        dfs(board,r+1,c);

        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i<m;i++)
        {
            if(board[0][i] == 'O')
            {
                // board[0][i] = '#';
                dfs(board,0,i);
            }
            if(board[n-1][i] == 'O')
            {
                // board[n-1][i] = '#';
                dfs(board,n-1,i);
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(board[i][0] == 'O')
            {
                // board[i][0] = '#';
                dfs(board,i,0);
            }
            if(board[i][m-1] == 'O')
            {
                // board[i][m-1] = '#';
                dfs(board,i,m-1);
            }
        }

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        return;
    }
};