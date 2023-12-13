class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        
        int cnt = 0;
        
        for(int i = 0;i<batteryPercentages.size();i++)
        {
            if(batteryPercentages[i]>0)
            {
                cnt++;
                for(int j = i+1;j<batteryPercentages.size();j++)
                {
                    batteryPercentages[j] = max(0,batteryPercentages[j]-1);
                }
            }
        }
        
        return cnt;
        
    }
};