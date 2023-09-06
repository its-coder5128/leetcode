class Solution {
public:
    int minDeletions(string s) {

        vector<int> vec(27,0);

        for(int i=0;i<s.size();i++)
        {
            vec[s[i] - 'a']++;
        }

        int ans = 0;
        
        sort(vec.begin(),vec.end(),greater<int>());

        for(int i=0;i<26;i++)
        {
            if(vec[i] <= vec[i+1])
            {
                int prev = vec[i+1];
                vec[i+1] = max(0,vec[i]-1);
                ans += prev - vec[i+1];
            }
        }
        return ans;
        
    }
};