class Solution {
public:
    string frequencySort(string s) {
        vector<int> arr(256,0);

        for(auto c:s)
            arr[c]++;
        
        vector<vector<int>> temp;

        for(int i = 0;i<(256);i++)
        {
            if(arr[i])
                temp.push_back({arr[i],i});
        }

        string ans = "";

        sort(temp.begin(), temp.end(),greater<vector<int>>());
        
        for(int i = 0;i<temp.size();i++)
        {
            for(int j = 0;j<temp[i][0];j++)
            {
                ans += temp[i][1];
            }
        }

        return ans;
    }
};