class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0;
        int right = 0;
        int n = cardPoints.size();

        for(int i = 0;i<k;i++)
        {
            left += cardPoints[i];
        }

        int maxi = left;

        for(int i = 1;i<=k;i++)
        {
            left -= cardPoints[k-i];
            right += cardPoints[n-i];

            maxi = max(maxi,left+right);
        }

        return maxi;
    }
};