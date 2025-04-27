class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                long req = ((target) - long(nums[i]+nums[j]));
                int k = j+1, l = n-1;
                while(k < l){
                    if(nums[k] + nums[l] == req){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(i+1 < n-2 and nums[i] == nums[i+1])i++;
                        while(j+1 < n-1 and nums[j] == nums[j+1])j++;
                        while(k+1 < l and nums[k] == nums[k+1])k++;
                        k++;
                        l--;
                    }
                    else if(nums[k] + nums[l] < req){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            } 
        }
        return ans;
    }
};