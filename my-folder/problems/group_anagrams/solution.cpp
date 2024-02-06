class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;

        for(int i = 0;i<strs.size();i++)
        {
            vector<int> arr(26,0);
            for(auto c:strs[i])
            {
                arr[c-'a']++;
            }
            string str = "";
            for(int i = 0;i<26;i++)
            {
                while(arr[i])
                {
                    str += 'a'+i;
                    arr[i]--;
                }
            }

            m[str].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto vec:m)
        {
            ans.push_back(vec.second);
        }

        return ans;
    }
};