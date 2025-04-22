class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0,pref = 0;
        vector<int> hsh(k);
        hsh[0]++;
        for(int i = 0; i < n; i++)
        {
            pref = (pref + nums[i])%k;
            if(pref < 0) pref += k;
            ans += hsh[pref];
            hsh[pref]++;
            
        }
        return ans;
        
    }
};
// [4,5,0,-2,-3,1]

// 1 0 1 0 3
// 0 1 2 3 4 

// i = 0,
// pref = 4
// ans = 0,pref = 4

// i = 1,
// pref =4
// ans = 1,pref = 4]

// i = 2,
// pref = 4
// ans = 3,pref = 4

// i = 3,
// pref = 2,
// ans = 3,pref = 2
