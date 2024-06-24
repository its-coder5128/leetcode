class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> m;

        for(auto it:hand)
            m[it]++;
        
        priority_queue<pair<int,int>> pq;

        for(auto it:m)
            pq.push({it.first,it.second});
        
        while(!pq.empty())
        {
            vector<pair<int,int>> temp;

            for(int i = 0;i<groupSize;i++)
            {
                if(pq.empty())
                    return false;
                pair<int,int> top = pq.top();
                pq.pop();

                temp.push_back({top.first,top.second - 1});
            }
            for(int i = groupSize-1;i>=1;i--)
            {
                if(temp[i].first != temp[i-1].first-1)
                    return false;
                if(temp[i].second > 0)
                    pq.push(temp[i]);
            }
            if(temp[0].second > 0)
                pq.push(temp[0]);
        }

        return true;
    }
};