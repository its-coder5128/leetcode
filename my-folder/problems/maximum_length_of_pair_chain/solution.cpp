class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1] < b[1])
            return true;
        if(a[1] == b[1])
            return a[0]<b[0];

        return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(),pairs.end(),cmp);

        int count = 1;
        int ele = pairs[0][1];

        for(int i=1;i<pairs.size();i++)
        {
            if(ele < pairs[i][0])
            {
                count++;
                ele = pairs[i][1];
            }
        }
        

        return count;
    }
};