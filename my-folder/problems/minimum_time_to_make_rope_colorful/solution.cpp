class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int time = 0;

        int prev = 0;
        int curr = 1;

        while(curr < colors.size())
        {
            if(colors[prev] == colors[curr])
            {
                if(neededTime[prev] < neededTime[curr])
                {
                    time += neededTime[prev];
                    prev = curr;
                    curr++;
                }
                else{
                    time += neededTime[curr];
                    curr++;
                }
            }
            else
            {
                prev = curr;
                curr++;
            }
        }

        return time;

        return 0;
        
    }
};