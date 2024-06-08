class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        
        int  n = skills.size();
        
        int i = 0;
        int j = 1;
        int cnt = 0;
        
        while(j<n)
        {
            if(skills[i] > skills[j])
            {
                j++;
                cnt++;
            }
            else
            {
                i = j;
                j++;
                cnt = 1;
            }
            
            if(cnt >= k)
                return i;
                
        }
        return i;
    }
};