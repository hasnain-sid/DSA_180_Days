class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size(),-1);
        stack<int> st;
        map<int,int> mp;
        nums2.push_back(-1);
        for(int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = i;
            while(st.size() and nums2[i] > nums2[st.top()]){
                ans[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = ans[mp[nums1[i]]];
        }
        return nums1;
    }
};