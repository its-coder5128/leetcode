class Solution {
public:
    bool isPali(string &str,int s,int e)
    {
        while(s<e)
        {
            if(str[s] == str[e]){
                s++;
                e--;
            }
            else
                return false;
        }
        return true;


    }
    void solve(string &str,int s,vector<vector<string>> &ans,vector<string> &temp)
    {
        if(s == str.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = s;i<str.size();i++)
        {
            if(isPali(str,s,i))
            {
                temp.push_back(str.substr(s,i-s+1));
                solve(str,i+1,ans,temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s,0,ans,temp);

        return ans;
    }
};