class Solution {
public:
    void solve(int open,int close,vector<string> &ans,string &temp)
    {
        if(close == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(open == close)
        {
            temp += '(';
            solve(open-1,close,ans,temp);
            temp.pop_back();
        }
        else
        {
            if(open > 0)
            {
                temp += '(';
                solve(open-1,close,ans,temp);
                temp.pop_back();
            }

                temp += ')';
                solve(open,close-1,ans,temp);
                temp.pop_back();

        }


    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        string temp = "";

        solve(n,n,ans,temp);

        return ans;
        
    }
};