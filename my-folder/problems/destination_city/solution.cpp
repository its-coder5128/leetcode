class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> m;

        for(int i = 0;i<paths.size();i++)
        {
            m[paths[i][0]]++;
        }
        for(int i = 0;i<paths.size();i++)
        {
            if(m[paths[i][1]] == 0)
                return paths[i][1];
        }

        return "";
        
    }
};