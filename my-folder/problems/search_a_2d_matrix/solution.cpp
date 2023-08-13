class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i = 0;
        int j = matrix[0].size()-1;

        while(i<matrix.size())
        {
            if(matrix[i][j] >= target)
            {
                //bin search
                int s = 0;
                int e = j;

                while(s<e)
                {
                    int mid = s + (e-s)/2;
                    
                    if(matrix[i][mid] >= target)
                        e = mid;
                    else
                        s = mid + 1 ;
                }

                if(matrix[i][s] == target)
                        return true;
                return false;
            }
            else{
                i++;
            }
        }

        return false;
    }
};