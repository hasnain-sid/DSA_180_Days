class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candi, int target, vector<int> subs, int i, int sum){
        if(sum == target){
            ans.push_back(subs);
            return;
        }
        if(i == candi.size()){
            return;
        }
        if(sum > target)
        {
            return;
        }
        
        
        sum+=candi[i];
        subs.push_back(candi[i]);
        helper(candi, target, subs, i+1, sum);
        sum-=candi[i];
        subs.pop_back();
        while(i+1 < candi.size() and candi[i] == candi[i+1])i++;
        helper(candi, target, subs, i+1, sum);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<int> subs;
        helper(candi,target,subs, 0, 0);
        return ans;
    }
};