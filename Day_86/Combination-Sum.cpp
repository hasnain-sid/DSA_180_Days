class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int> &nums,vector<int> &output,int ind,int target,int sum)
    { 
        if(sum > target)
        {
            return;
        }
        if(target==sum)
        {
            ans.push_back(output);
            return;
        }
        if(ind == nums.size())
        {
            return;
        }
        // not take
        combination(nums,output,ind+1,target,sum);
        //take
        int element = nums[ind];
        sum += element;
        output.push_back(element);
        combination(nums,output,ind,target,sum);
        // BACKTRACKING STEP
        sum -= element; 
        output.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> output;
        combination(nums,output,0,target,0);
        return ans;
    }
};