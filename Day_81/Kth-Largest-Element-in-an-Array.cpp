class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int sz = nums.size();
        for(auto it: nums){
            pq.push(it);
            if(pq.size() > sz - k + 1){
                pq.pop();
            }
        }
        return pq.top();
    }
};