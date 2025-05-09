class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size(),i = 0, j = n-1;
        while(i < j){
            if(t == nums[i] + nums[j]){
                return {i+1,j+1};
            }
            else if(t < nums[i] + nums[j]){
                j--;
            }
            else
                i++;
        }
        return {};
    }
};