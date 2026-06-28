1class Solution {
2public:
3    vector<int> dp;
4    int helper(int i,string &s)
5    {
6        if(i >= s.size())
7            return 1;
8        if(dp[i] != -1)
9            return dp[i];
10        int ans = 0;
11        int op1 = s[i] - '0';
12        int op2 = 0;
13        
14        if(i < s.size()-1)
15        {
16            op2 =  op1*10 + (s[i+1] - '0');
17
18        }
19        if(op1 > 0) ans = helper(i+1,s);
20        if(op1 > 0 and (op2 > 0 and op2 < 27)) ans += helper(i+2,s);
21        return dp[i] = ans;
22    }
23    int numDecodings(string s) {
24        for(int i = 0; i < s.size() + 5; i++ )
25            dp.push_back(-1);
26        return helper(0,s);
27        
28    }
29};