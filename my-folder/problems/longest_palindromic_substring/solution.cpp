class Solution {
public:
    void Pali(int l,int r,int &maxi,string &ans,string &s)
    {
        //cout<<"hi";
        //ans = "hi";
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;
            r++;
        }

        l++;
        r--;

        int len = r-l+1;

        if(maxi < len)
        {
            maxi = len;
            cout<<s.substr(l,len);
            ans = s.substr(l,len);
        }

        return;
    }
    string longestPalindrome(string s) {

        string ans="";
        int maxi = -1;

        for(int i=0;i<s.size();i++)
        {
            Pali(i,i,maxi,ans,s);

            Pali(i,i+1,maxi,ans,s);
        }

        return ans;
        
    }
};