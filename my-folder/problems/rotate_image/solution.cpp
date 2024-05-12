class Solution {
public:
    void swappy(vector<vector<int>>& matrix,int &nextRow,int &nextCol)
    {
        int n = matrix.size();
        int currRow = nextRow;
        int currCol = nextCol;
        nextRow = n-1-currCol;
        nextCol = currRow;

        swap(matrix[currRow][currCol],matrix[nextRow][nextCol]);
    }
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for(int i =0;i<n/2;i++)
        {
            for(int j = i;j<n-i-1;j++)
            {
                int nextRow = n-1-j;
                int nextCol = i;

                swappy(matrix,nextRow,nextCol);
                swappy(matrix,nextRow,nextCol);
                swappy(matrix,nextRow,nextCol);
                // swap(matrix[currRow][currCol],matrix[nextRow][nextCol]);

                // currRow = nextRow;
                // currCol = nextCol;
                // nextRow = n-1-currCol;
                // nextCol = currRow;

                // swap(matrix[currRow][currCol],matrix[nextRow][nextCol]);
                
                // currRow = nextRow;
                // currCol = nextCol;
                // nextRow = n-1-currCol;
                // nextCol = currRow;

                // swap(matrix[currRow][currCol],matrix[nextRow][nextCol]);
            }
        }
        
    }
};