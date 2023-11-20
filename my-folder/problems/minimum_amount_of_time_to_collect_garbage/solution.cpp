class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int maxG = 0, maxP = 0, maxM = 0;
        int sum = 0;
        int prefix_sum = 0;
        for(int i = 0;i<garbage.size();i++)
        {
            for(int j = 0;j<garbage[i].size();j++)
            {
                sum++;
                if(garbage[i][j] == 'M')
                    maxM = prefix_sum;
                else if(garbage[i][j] == 'G')
                    maxG = prefix_sum;
                else
                    maxP = prefix_sum;
            }
            if(i <= travel.size()-1)
                prefix_sum += travel[i];
           
        }

        return sum + maxM + maxG + maxP;
        
    }
};