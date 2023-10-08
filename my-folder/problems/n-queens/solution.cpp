class Solution {
public:
    bool canWe(vector<string> &board,int row,int col)
    {
        for(int i = 0;i<board[0].size();i++)
        {
            if(board[i][col] == 'Q' || board[row][i] == 'Q' || 
               (row-i >=0 && col-i>=0 && board[row-i][col-i] == 'Q') || 
                   (row-i >=0 && col+i<board[0].size() && board[row-i][col+i] == 'Q'))
                return false;
        }

        return true;
    }
    void solve(int row,int n,vector<vector<string>>& ans,vector<string> &board)
    {
        if(row >= n)
        {
            
            ans.push_back(board);
            
            return;
        }

        for(int col=0;col<n;col++)
        {
            if(canWe(board,row,col))
            {
                board[row][col] = 'Q';
                solve(row+1,n,ans,board);
                board[row][col] = '.';
            }
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0,n,ans,board);

        return ans;
        
    }
};