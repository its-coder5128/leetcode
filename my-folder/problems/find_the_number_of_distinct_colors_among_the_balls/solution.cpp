class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> m;
        unordered_map<int,unordered_set<int>> ms;
        
        vector<int> ans;
        
        for(auto it:queries)
        {
            if(m.find(it[0]) != m.end())
            {
                ms[m[it[0]]].erase(it[0]);
                if(ms[m[it[0]]].empty())
                    ms.erase(m[it[0]]);
                ms[it[1]].insert(it[0]);
                m[it[0]] = it[1];
            }
            else{
                ms[it[1]].insert(it[0]);
                m[it[0]] = it[1];
            }
            
            ans.push_back(ms.size());
        }
        
        return ans;
    }
};