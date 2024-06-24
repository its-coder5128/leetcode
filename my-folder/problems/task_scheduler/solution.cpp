class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;

        vector<int> m(26,0);

        for(auto it:tasks)
            m[it-'A']++;
        
        for(auto it:m)
        {
            if(it != 0)
                pq.push(it);
        }
        
        int ans = 0;

        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            top--;
            ans++;
            if(top == 0)
            {
                ans += pq.size();
                break;
            }

            vector<int> temp;
            int size = pq.size();
            for(int i = 0;i<min(n,size);i++)
            {
                if(pq.top()-1 > 0)
                    temp.push_back(pq.top()-1);
                pq.pop();
            }
            ans += n;

            pq.push(top);

            for(int i = 0;i<temp.size();i++)
            {
                if(temp[i] > 0)
                    pq.push(temp[i]);
            }
        }

        return ans;

    }
};