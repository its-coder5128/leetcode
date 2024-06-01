class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int nColor = color;
        color = image[sr][sc];

        if(color == nColor)
            return image;
            
        queue<pair<int,int>> q;
        q.push({sr,sc});

        
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            image[r][c] = nColor;

            for(int i = 0;i<4;i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];

                if(nRow >= 0 && nCol >=0 && nRow < image.size() && nCol < image[0].size() && image[nRow][nCol] == color)
                {
                    q.push({nRow,nCol});
                }
            }
        }

        return image;


    }
};