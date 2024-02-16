class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;

        for(auto num:arr)
            m[num]++;
        
        vector<int> temp(m.size(),0);
        int j = 0;
        for(auto i:m)
        {
            temp[j++] = i.second;
        }

        sort(temp.begin(),temp.end());

        int ans = temp.size();

        for(int i = 0;i<(temp.size()) && k;i++)
        {
            if(temp[i] <= k)
            {
                ans--;
                k = k - temp[i]; 
            }
            else
                break;
        }

        return ans;
    }
};