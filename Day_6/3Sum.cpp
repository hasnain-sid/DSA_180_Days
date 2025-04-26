class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            int j = i+1, k = nums.size()-1;
            while(i+1 < nums.size() and nums[i] == nums[i+1])i++;
            int req = -1 * (nums[i]);
            while(j < k){
                if(nums[j] + nums[k] == req){
                    // while(i+1 < nums.size()-2 and nums[i] == nums[i+1])i++;
                    while(j < k-1 and nums[j] == nums[j+1])j++;
                    // while(k-1 > j and nums[k] == nums[k-1])k--;
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                }
                else if(nums[j]+ nums[k] > req){
                    k--;
                }
                else{
                    j++;
                }
            }
            
        }
        return ans;
        
    }
};