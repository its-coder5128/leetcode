class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int ans = 0;
        int securityDevice = 0;

        for(int i = 0;i<bank.size();i++)
        {
            int x = 0;
            for(int j = 0;j<bank[0].size();j++)
            {
                if(bank[i][j] == '1')
                    x++;
            }
            if(x == 0)
                continue;
            else{
                ans += securityDevice*x;
                securityDevice = x;
            }
        }

        return ans;
        
    }
};