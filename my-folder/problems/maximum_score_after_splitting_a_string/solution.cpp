class Solution {
public:
    int maxScore(string s) {

        int left = 0;
        int right = 0;

        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '1')
                right++;
        }

        int maxi = INT_MIN;

        for(int i = 0;i<s.size()-1;i++)
        {
            if(s[i] == '0')
                left++;
            else
                right--;
            
            maxi =max(maxi,left+right);
        }

        return maxi;
        
    }
};