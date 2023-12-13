class Solution {
public:
    int solve(int a,int b,int m)
    {
        int ans = 1;
        for(int i = 0;i<b;i++)
        {
            ans = (ans*a)%m;
        }
        
        return ans;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        
        vector<int> ans;
        
        for(int i = 0;i<variables.size();i++)
        {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            
            int x = solve(a,b,10);
            int y = solve(x,c,m);
            
            if(y == target)
                ans.push_back(i);
        }
        
        return ans;
    }
};