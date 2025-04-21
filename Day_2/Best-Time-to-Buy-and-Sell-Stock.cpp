class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minm = p[0];
        int ans = 0;
        for(int i = 1; i < p.size(); i++){
            minm = min(minm,p[i]);
            ans = max(ans,p[i]-minm);
        }
        return ans;

        
    }
};