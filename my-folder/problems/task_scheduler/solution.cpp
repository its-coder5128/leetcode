class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> charSet(26,0);

        for(int i = 0;i<tasks.size();i++)
        {
            charSet[tasks[i] - 'A']++;
        }

        priority_queue<int> q;

        for(int i = 0;i<26;i++)
        {
            if(charSet[i])
                q.push(charSet[i]);
        }

        int ans = 0;

        while(!q.empty())
        {
            int top = q.top()-1;
            q.pop();

            ans++;

            vector<int> temp;

            for(int i = 0;i<n&&(!q.empty());i++)
            {
                temp.push_back(q.top()-1);
                q.pop();
            }

            int x = temp.size();

            if(top)
                q.push(top);

            for(auto i : temp)
            {
                if(i)
                    q.push(i);
            }

            if(q.size() == 0)
                ans += x;
            else{
                ans += max(x,n);
            }

        }

        return ans;
    }
};