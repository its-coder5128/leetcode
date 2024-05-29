class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> m1(256,0);
        vector<int> m2(256,0);

        for(auto c:t)
            m2[c]++;
        
        int start = 0;
        int end = -1;
        int mini = INT_MAX;
        int req = t.size();

        int l = 0;
        int r = 0;

        while(r<n)
        {
            if(m2[s[r]]>0)
                req--;
            m2[s[r]]--;

            while(req <= 0)
            { 
                if(mini > r - l + 1)
                {
                    mini = r - l + 1;
                    start = l;
                    end = r;
                }
                
                m2[s[l]]++;
                if(m2[s[l]] > 0)
                    req++;
                l++;
            }
            r++;
        }

        return s.substr(start,end-start+1);
        
    }
};