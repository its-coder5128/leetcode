class Solution {
public:
    int maxCoins(vector<int>& piles) {

        sort(piles.begin(),piles.end(),greater<int>());

        int n = piles.size();

        int sum = 0;

        for(int i = 1;i<(n - n/3);i = i+2)
        {
            cout<<piles[i]<<" ";
            sum += piles[i];
        }
        return sum;
    }
};