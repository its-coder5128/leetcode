class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(-1);
        unordered_map<int,int> mp;
        int m = nums2.size();
        int n = nums1.size();

        vector<int> ans(n,0);


        for(int i = m-1;i>=0;i--)
        {
            while(st.top() != -1 && nums2[i] >= nums2[st.top()])
                st.pop();

            if(st.top() != -1)
                mp[nums2[i]] = nums2[st.top()];
            else
                mp[nums2[i]] = -1;

            st.push(i);
        }

        for(int i = 0;i<n;i++)
            ans[i] = mp[nums1[i]];
        
        return ans;
    }
};