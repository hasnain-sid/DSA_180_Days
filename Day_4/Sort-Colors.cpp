class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0;
        int two = 0;
        int zero = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
                one++;
            else if(nums[i] == 2)
                two++;
            else 
                zero++;
        }
        int k = 0;
        while(zero--)
        {
            nums[k] = 0;
            k++;
        }
            
        while(one--)
        {
            nums[k] = 1;
            k++;
        }
        while(two--)
        {
            nums[k] = 2;
            k++;
        }
    }
};