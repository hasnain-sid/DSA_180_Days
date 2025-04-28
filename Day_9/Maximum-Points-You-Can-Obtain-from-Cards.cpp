class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int suffix_sum = 0;
        for(int i = n-1; i >= n - k; i--)
        {
            suffix_sum += cp[i];
        } 
        int i = 0,j = n-k,sum = 0;
        int ans= suffix_sum;
        while(i < k)
        {
            sum += cp[i];
            suffix_sum -= cp[j];
            ans = max(ans,sum  + (suffix_sum));
            i++;
            j++;
        }
        return ans;
    }
};
