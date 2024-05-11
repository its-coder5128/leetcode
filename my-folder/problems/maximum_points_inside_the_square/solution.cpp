class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        unordered_map<char,int> m;
        
        int maxi = INT_MAX;
        
        int n = points.size();
        
        for(int i = 0;i<n;i++)
        {
            if(m.find(s[i]) == m.end())
            {
                int x = max(abs(points[i][0]),abs(points[i][1]));
                m[s[i]] = x;
            }
            else{
                if( m[s[i]] > max(abs(points[i][0]),abs(points[i][1])))
                {
                    maxi = min(maxi,m[s[i]]);
                    int x = max(abs(points[i][0]),abs(points[i][1]));
                    m[s[i]] = x;
                }
                else{
                    maxi = min(maxi,max(abs(points[i][0]),abs(points[i][1])));
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if(max(abs(points[i][0]),abs(points[i][1])) < maxi)
                cnt++;
        }
        return cnt;
    }
};