class Solution {
public:
    // class cmp
    // {
    //     public:
    //     bool operator()(string &a,string &b)
    //     {
    //         return a>b;
    //     }
    // };
    void dfs(unordered_map<string,priority_queue<string,vector<string>,greater<string>>> &m,string from,vector<string> &ans)
    {

        while(!m[from].empty())
        {
            string aux = m[from].top();
            m[from].pop();
            dfs(m,aux,ans);
        }
            ans.push_back(from);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> m;

        for(int i=0;i<tickets.size();i++)
        {
            string u = tickets[i][0];
            string v = tickets[i][1];

            m[u].push(v);
        }
        
        vector<string> ans;
        //cout<<m["JFK"].size();
        dfs(m,"JFK",ans);

        reverse(ans.begin(),ans.end());

        return ans;

    }
};