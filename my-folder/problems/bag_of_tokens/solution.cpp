class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score  = 0,maxi = 0;

        sort(tokens.begin(),tokens.end());

        int i = 0,j = tokens.size() - 1;

        while(i<=j)
        {
            if(tokens[i] <= power)
            {
                power -= tokens[i++];
                score++;
                maxi = max(score,maxi);
            }
            else if( score>=1 )
            {
                power += tokens[j--];
                score--;
            }
            else
                break;
        }

        return maxi;
    }
};