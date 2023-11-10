class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        unordered_map<int,bool> vis;
        unordered_map<int,list<int>> m;
        int start;

        for(int i = 0;i < arr.size();i++)
        {
            m[arr[i][0]].push_back(arr[i][1]);
            m[arr[i][1]].push_back(arr[i][0]);
        }

        for(auto i : m)
        {
            if(i.second.size()==1)
            {
                start = i.first;
                break;
            }
        }

        vector<int> ans;
        ans.push_back(start);
        vis[start] = 1;

        while(ans.size() < arr.size() + 1)
        {
            for(auto i : m[start])
            {
                if(!vis[i])
                {
                    start = i;
                    vis[i] = 1;
                }
            }

            ans.push_back(start);
        }

        return ans;


        
    }
};