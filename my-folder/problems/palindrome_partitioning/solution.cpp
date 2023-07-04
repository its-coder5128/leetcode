class Solution {
public:
    bool isPali(string s)
    {
        string r=s;
        reverse(s.begin(),s.end());

        if(s==r)
            return true;
        else
            return false;    
    }
    void solve(string s,vector<vector<string>> &ans,vector<string> &temp,int n,int index)
                
    {
        if(index==n)
        {
            ans.push_back(temp);
            cout<<"BASE ";
            return;
        }
        string aux;
        
        for(int i=index;i<n;i++)
        {
            aux.push_back(s[i]);
            cout<<"IN "<<aux<<" ";
            if(isPali(aux))
            {
                cout<<"INIF ";
                temp.push_back(aux);
                solve(s,ans,temp,n,i+1);
                temp.pop_back();
                cout<<"INIFB ";
            }
            

        }

    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        

        solve(s,ans,temp,n,0);

        return ans;
    }
};