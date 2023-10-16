class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> s;
        s.push(-1);
        unordered_map<int,int> m;

        for(int i = nums2.size()-1 ;i>=0;i--)
        {
            while(s.top() != -1 && s.top() <= nums2[i])
            {
                s.pop();
            }
            m[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }

        return ans;


        
    }
};