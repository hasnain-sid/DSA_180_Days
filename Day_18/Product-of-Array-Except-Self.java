class Solution {
       public int[] productExceptSelf(int[] nums) {
       int length = nums.length;
       int[] ans = new int[length];
       Arrays.fill(ans, 1);
       int prefix = 1;
       for(int i=0; i < length; i ++){
           ans[i] = ans[i] * prefix;
           prefix = prefix * nums[i];
       }
       int suffix = 1;
       for(int i = length-1; i >= 0; i--){
           ans[i] = ans[i] * suffix;
           suffix = suffix * nums[i];
       }
       return ans;
   }

}