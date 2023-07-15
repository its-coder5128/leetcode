class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int maxi=0;

        cout<<n;

        unordered_map<char,int> m;
        int i=0,j=0;
        while(i<n)
        {
            m[s[i]]++;
            if(m.size() == i-j+1)
            {
                maxi = max(maxi,i-j+1);
            }
            else if(m.size() < i-j+1){
                while(m.size()<i-j+1)
                {
                    m[s[j]]--;
                    if(m[s[j]] == 0)
                    {
                        m.erase(s[j]);
                    }

                    j++;
                }
            }
            i++;
        }

        return maxi;
        
    }
};