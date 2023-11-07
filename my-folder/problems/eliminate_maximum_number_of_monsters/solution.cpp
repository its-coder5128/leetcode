class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> time;

        for(int i =0;i<dist.size();i++)
        {
            time.push_back((float)((float)dist[i]/(float)speed[i]));
        }

        sort(time.begin(),time.end());

        for(int i = 0;i<time.size();i++)
        {
            if(time[i] <= i)
            {
                return i;
            }
            
        }

        return time.size();
    }
};