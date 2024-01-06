class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<vector<int>> jobs;

        for(int i=0;i<profit.size();i++)
        {
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());
        
        vector<int> end;
        vector<int> prof;
        end.push_back(0);
        prof.push_back(0);

        for(auto num:jobs)
        {
            int index = upper_bound(end.begin(),end.end(),num[1]) - end.begin();

            if(index == end.size())
            {
                end.push_back(num[0]);
                prof.push_back(prof[prof.size()-1] + num[2]);
            }else{
                if(num[2] + prof[index-1] > prof[prof.size()-1])
                {
                    end.push_back(num[0]);
                    prof.push_back(prof[index-1] + num[2]);
                }
            }
        }

        return prof[prof.size()-1];
        
        
    }
};