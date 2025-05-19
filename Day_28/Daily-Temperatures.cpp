class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    {
        int hottest = INT_MIN;
        vector<int>  ans(t.size(),0);
        for(int i = t.size()-1; i >= 0; i--)
        {
            if(t[i] >= hottest)
            {
                hottest = t[i];
            }
            else
            {
                int it = i+1;
                while(t[it] <= t[i])
                {
                    it += ans[it];
                }
                ans[i] = it - i;
            }
        }
        return ans;
     
    }
};