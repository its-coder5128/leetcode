class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {

        int size = cost.size();
        int t = 0;
        vector<int> next(size+1,1e9);

        for(int index = size-1;index>=0;index--)
        {
            for(int n = size;n>=0;n--)
            {
                int exclude = next[n];

                int include = cost[index]; 
                if(n-time[index]-1>0)
                    include += next[n-time[index]-1];

                next[n] = min(exclude,include);
            }
        }
        return next[size];
    }
};