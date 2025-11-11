class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &nums, vector<int> &subset,int ind)
    {
        if(ind == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        // pick
        subset.push_back(nums[ind]);
        helper(nums,subset,ind+1);
        subset.pop_back();

        // not pick
        while(ind + 1< nums.size() and nums[ind] == nums[ind+1])ind++;
        helper(nums,subset,ind+1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        helper(nums,subset,0);
        return ans;
        
    }
};