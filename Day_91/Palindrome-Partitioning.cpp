class Solution {
public:
    bool ispalindrome(string s)
    {
        int n = s.length();
        if (n <= 1)
            return true;
        else if (n == 2 && s[1] == s[0])
            return true;
        else if (n == 2 && s[0] != s[1])
            return false;
        else if (s[0] != s[n - 1])
            return false;
        else
            return ispalindrome(s.substr(1, n - 2));
    }
    void helper(vector<vector<string>> &ans_subset, string &s,int ind,vector<string> &subset)
    {
        if(ind == s.size())
        {
            ans_subset.push_back(subset);
            // subset.clear();
            return;
        }
        for(int i = ind; i < s.size(); i++)
        {
            if(ispalindrome(s.substr(ind,i-ind+1)))
            {
                subset.push_back(s.substr(ind,i - ind + 1));
                helper(ans_subset,s,i+1,subset);
                subset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans_subset;
        vector<string> subset;
        string tmp;
    
        helper(ans_subset,s,0,subset);
        return ans_subset;
        
    }
};