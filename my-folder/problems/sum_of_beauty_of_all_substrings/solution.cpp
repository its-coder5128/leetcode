class Solution {
public:
    int beautySum(string s) {
        
        int n = s.size();
        int sum = 0;

        for(int i = 0;i<n;i++)
        {
            
            vector<int> m(26,0);
            for(int j = i;j<n;j++)
            {
                
                int x = s[j] - 'a';
                m[x]++;
                int mini = INT_MAX;
                int maxi = -1;
                
                for(auto it:m)
                {
                    if(it != 0)
                    {
                        maxi = max(it,maxi);
                        mini = min(it,mini);
                    }
                }
                sum += maxi-mini;
                // cout<<sum<<" "<<i<<" "<<j<<endl;
            }
        }

        return sum;
    }
};