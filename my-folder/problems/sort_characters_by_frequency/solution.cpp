class Solution {
public:
    string frequencySort(string s) {
        vector<vector<int>> arr(256,vector<int>(2,0));

        for(auto c:s)
        {
            arr[c][0]++;
            arr[c][1] = c;
        }

        sort(arr.begin(),arr.end(),greater<vector<int>>());
        
        string ans = "";

        for(int i = 0;i<256;i++)
        {
            int x = arr[i][0];
            for(int j = 0;j<x;j++)
            {
                ans += arr[i][1];
            }
        }

        return ans;
    }
};