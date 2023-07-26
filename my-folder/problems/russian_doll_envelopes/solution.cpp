class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(),envelopes.end(),cmp);


        vector<int> arr;
        arr.push_back(envelopes[0][1]);

        for(int i=1;i<envelopes.size();i++)
        {
            if(arr.back()<envelopes[i][1])
            {
                arr.push_back(envelopes[i][1]);
            }
            else{
                int index = lower_bound(arr.begin(),arr.end(),envelopes[i][1]) - arr.begin();

                arr[index]=envelopes[i][1];
            }
        }


        return arr.size();
        
    }
};