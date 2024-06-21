class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        vector<int> ans;
        int n = arr.size();

        for(int i = n-1;i>=0;i--)
        {
            int comming = arr[i];

            while(!st.empty() && comming > 0 && st.top() <= 0  && comming > abs(st.top()))
                st.pop();
            
            if(!st.empty() && comming > 0 && st.top() <= 0  && comming == abs(st.top()))
                st.pop();
            else if(!st.empty() && comming > 0 && st.top() <= 0  && comming < abs(st.top()))
                continue;
            else
                st.push(comming);
        }


        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
        
        
    }
};