class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &visited, int delRow[], int delCol[]){
        int n= board.size();
        int m= board[0].size();

        visited[row][col]= 1;

        for(int i= 0; i< 4; i++){
            int newRow= row+ delRow[i];
            int newCol= col+ delCol[i];

            if(newRow>= 0 && newRow< n && newCol>= 0 && newCol< m && visited[newRow][newCol]== 0 && board[newRow][newCol]== 'O'){
                dfs(newRow, newCol, board, visited, delRow, delCol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int delRow[4]= {0, 1, 0, -1};
        int delCol[4]= {1, 0, -1, 0};

        for(int i= 0; i< n; i++){
            if(board[i][0]== 'O' && !visited[i][0]) dfs(i, 0, board, visited, delRow, delCol);
            if(board[i][m- 1]== 'O' && !visited[i][m- 1]) dfs(i, m- 1, board, visited, delRow, delCol);
        }

        for(int j= 0; j< m; j++){
            if(board[0][j]=='O' && !visited[0][j]) dfs(0, j, board, visited, delRow, delCol);
            if(board[n- 1][j]== 'O' && !visited[n- 1][j]) dfs(n- 1, j, board, visited, delRow, delCol);
        }

        for(int i= 0; i< n; i++){
            for(int j= 0; j< m; j++){
                if(board[i][j]== 'O' && !visited[i][j]) board[i][j]= 'X';
            }
        }
    }
};