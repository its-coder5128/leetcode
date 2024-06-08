class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<int> removed(n,0);
        
        int j = 0;
        
        while(j != n)
        {
            if(s[j] >= '0' && s[j] <= '9')
            {
                removed[j] = 1;
                int i = j - 1;
                while(i>=0 && removed[i] == 1)
                {
                    i--;
                }
                if(i == -1)
                    return  "";
                removed[i] = 1;
            }
            j++;
        }
        
        string ans = "";
        
        for(int i = 0;i<n;i++)
        {
            if(removed[i] == 0)
                ans += s[i];
        }
        
        return ans;
    }
};