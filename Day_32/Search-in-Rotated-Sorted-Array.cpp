class Solution {
public:
    int start=0,end=0;

    int search(vector<int>& arr, int target) {
        int size = arr.size();
        end = size - 1;
        int mid=(start+end)/2;
        while(start<end){
            if(arr[mid]>=arr[0]){
                start=mid+1;
            }else end=mid;
            mid=(end+start)/2;
        }
        if(arr[start] <= target and arr[size-1] >= target)
        {
            int ind = lower_bound(arr.begin()+start,arr.end(),target)-arr.begin();
            if(ind != size)
            {
                if(arr[ind] == target)
                    return ind;
                else
                    return -1;
            }
            else
            return -1;
        }
        else 
        {
            int ind = lower_bound(arr.begin(),arr.begin()+start,target)-arr.begin();
            if(ind != start)
            {
                if(arr[ind] == target)
                    return ind;
                else
                    return -1;
            }
            else
            return -1;
        }
        // cout << start << \ \ << end << endl;
        return 0;
    }
};