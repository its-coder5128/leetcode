class Solution {
public:
    class cmp{
        public:

        bool operator()(pair<int,int> &a,pair<int,int> &b)
        {
            if(a.second>b.second)
                return true;
            return false;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        vector<int> ans;

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        for(auto i:m)
        {
            if(q.size() < k)
            {
                q.push({i.first,i.second});
            }
            else{
                if(q.top().second < i.second)
                {
                    q.pop();
                    q.push({i.first,i.second});
                }
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.top().first);
            q.pop();
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};