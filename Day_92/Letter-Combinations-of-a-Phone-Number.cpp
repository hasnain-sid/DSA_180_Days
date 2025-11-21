class Solution {
public:
    vector<string> help(string &st, vector<string> &ans, unordered_map<char,string> &mp,string &xo,int ind)
    {
        cout <<"size->" << " " << st.size() << endl;
        if(xo.size() == st.size())
        {
            cout << xo << endl;
            ans.push_back(xo);
            // xo.clear();
            return ans;
        }
        // for(int i = 0; i < st.size(); i++)
        // {
            string s = mp[st[ind]];
            for(int j = 0; j < s.size(); j++)
            {
                xo.push_back(s[j]);
                help(st,ans,mp,xo,ind+1);
                xo.pop_back();
                // help(st,ans,mp,xo,ind);
            }
        // }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map<char,string> mp;
        int j = 97;
        for(int i = 2; i <= 8; i++)
        {
            string tmp;
            for(int k = 1; k <= 3; k++)
            {
                tmp.push_back(char(j++));
                if(i==7 and k==3) tmp.push_back(char(j++));
            }
            mp[char(i+48)] = tmp;
            tmp.clear();
        }
        mp['9'] = "wxyz";
        // for(auto it:mp)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }
        string t;
        vector<string> vs;
        // vector<string > ans = 
        return help(digits,vs,mp,t,0);

        // return vs;
        
    }
};