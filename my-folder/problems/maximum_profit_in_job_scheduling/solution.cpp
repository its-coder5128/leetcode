class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();

        int size = 0;

        vector<vector<int>> jobs(n,vector<int>(3,0));

        for(int i = 0;i<n;i++)
        {
            jobs[i][0] = endTime[i];
            jobs[i][1] = startTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(),jobs.end());

        vector<int> end;
        vector<int> prof;

        end.push_back(0);
        prof.push_back(0);

        for(int i = 0;i<n;i++)
        {
            int index = upper_bound(end.begin(),end.end(),jobs[i][1]) - end.begin();

            if(index == end.size())
            {
                end.push_back(jobs[i][0]);
                prof.push_back(jobs[i][2] + prof.back());
            }
            else
            {
                if(prof.back() < jobs[i][2] + prof[index-1])
                {
                    end.push_back(jobs[i][0]);
                    prof.push_back(jobs[i][2] + prof[index-1]);
                }
            }
        }

        return prof.back();
        
    }
};