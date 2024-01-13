class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> arr(26,0);
        int cnt = 0;

        for(int i = 0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }

        for(int i = 0;i<t.size();i++)
        {
            if(arr[t[i]-'a'] == 0)
                cnt++;
            else
                arr[t[i]-'a']--;
        }

        return cnt;
        
    }
};