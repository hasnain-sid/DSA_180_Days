class Solution {
public:
    int removeDuplicates(vector<int>& v) {
            set<int> st;
            for(int i = 0; i < v.size(); i++)
            {
                st.insert(v[i]);
            }
            auto it = st.begin();
            for(int i = 0; i < st.size(); i++)
            {
                v[i] = *it;
                it++;
            }
            return st.size();

    }
};