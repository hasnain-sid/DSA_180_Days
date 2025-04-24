class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vp;
        for(int i = 0; i < nums.size(); i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        
        for(int i = 0; i < vp.size(); i++){
            int req = target - vp[i].first;
            
            // Binary search for the required value
            int left = 0;
            int right = vp.size() - 1;
            
            while(left <= right){
                int mid = left + (right - left) / 2;
                
                if(vp[mid].first == req && mid != i){
                    // Found the required value
                    return {vp[i].second, vp[mid].second};
                }
                else if(vp[mid].first < req){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        
        // If no solution is found (though the problem guarantees one exists)
        return {};
    }
};