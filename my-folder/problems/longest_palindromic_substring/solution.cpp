class Solution {
public:
    string solve(string s,int i,int j)
    {
        int n = s.size();
        if(j == n)
            return "";
        
        while(i>=0 && j<n)
        {
            if(s[i] == s[j])
            {
                i--;
                j++;
            }
            else
                break;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int maxi = -1;
        string ans = "";
        int n = s.size();

        for(int i = 0;i<n;i++)
        {
            string str1 = solve(s,i,i);
            string str2 = solve(s,i,i+1);

            // cout<<str1.size()<<" "<<str2.size()<<" "<<maxi<<endl;
            int x = str1.size();
            int y = str2.size();
            if(x >= y && x > maxi)
            {
                // cout<<str1<<" "<<str2<<" "<<i<<endl;
                
                maxi = str1.size();
                ans = str1;
            }
            else if(y > x && y > maxi)
            {
                maxi = str2.size();
                ans = str2;
            }

        }

        return ans;
    }
};