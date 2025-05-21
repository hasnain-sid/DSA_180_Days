class Solution {
public:
    vector<int> prevSmallerElement(vector<int> &h)
    {
        int n = h.size();
        stack<int> st; 
        st.push(-1);
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            int curr = h[i];
            while(st.top() != -1 and h[st.top()] >= curr)
            {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int> &h)
    {
        int n = h.size();
        stack<int> st; 
        st.push(-1);
        vector<int> ans;

        for(int i = n-1; i >= 0; i--)
        {
            int curr = h[i];
            while(st.top() != -1 and h[st.top()] >= curr)
            {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& h) {

        vector<int> pre = prevSmallerElement(h);
        vector<int> next = nextSmallerElement(h);
        
        // since we are using push_back
        reverse(next.begin(),next.end());
        
        int ans = INT_MIN;

        for(int i = 0; i < h.size(); i++)
        {
            int l = h[i];
            if(next[i] == -1)
                next[i] = h.size();
            int wid = next[i] - pre[i] - 1;
            ans = max(ans,l*wid);

        }
        return ans;

    }
};