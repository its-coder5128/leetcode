class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        ans.push_back({1});

        for(int i = 1;i<numRows;i++)
        {
            vector<int> temp(i+1,0);
            for(int j = 0;j<=i;j++)
            {
                int n = ans[i-1].size();
                
                if(n-1 >= j)
                    temp[j] += ans[i-1][j];
                if(j-1 >= 0)
                    temp[j] += ans[i-1][j-1];
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};