class Solution {
public:
    string paliString(string &str,int i,int j)
    {
        int s = i;
        int e = j;

        while(s>=0 && e<str.size() && str[s] == str[e])
        {
            s--;
            e++;
        }
        s++;
        e--;

        return str.substr(s,e-s+1);
    }
    string longestPalindrome(string &s) {

        string ans = "";
        int maxi = 0;

        for(int i=0;i<s.size();i++)
        {
            string temp1 = paliString(s,i,i);
            string temp2 = paliString(s,i,i+1);
            //cout<<i<<" "<<temp<<" "<<maxi<<" "<<temp.size()<<endl;

            if(maxi<temp1.size())
            {
                ans = temp1;
                //cout<<ans<<endl;
                maxi = temp1.size();
            }
            if(maxi<temp2.size())
            {
                ans = temp2;
                //cout<<ans<<endl;
                maxi = temp2.size();
            }
        }

        return ans;
        
    }
};