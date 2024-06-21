class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        st.push(-1);

        for(int i = 2*n-1;i>=0;i--)
        {
            while(st.top() != -1 && nums[i%n] >= nums[st.top()%n])
                st.pop();

            if(st.top() != -1)
                ans[i%n] = nums[st.top()%n];
            
            st.push(i);
        }

        return ans;
    }
};