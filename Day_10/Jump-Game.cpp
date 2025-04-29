class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int max = -1;
        if(n==1)
        return true;
        else if(a[0] == 0)
        return false;
        for(int i = n-1; i >= 0; --i)
        {
            int ind = -1;
            int j;
            for(j = i-1; j >= 0; j--)
            {
                if(i - j <= a[j] )
                {
                    i = j+1;
                    ind = i;
                    break;
                }
                
            }           
            if(i == 0)
            return true;
            if(ind == -1)
            return false;
            
        }
        return false;
        
    }
};
