1class Solution {
2public:
3    int dp[13][10010]; 
4
5    int func(int amount, vector<int>& coins, int ind) {
6        if (amount == 0) return 0;
7        if (ind == coins.size()) return INT_MAX;
8
9        if (dp[ind][amount] != -1) return dp[ind][amount];
10
11        long long int opr1 = INT_MAX, opr2 = INT_MAX;
12
13        // Choice 1: Pick the current coin (stay at the same index 'ind' for reuse)
14        if (amount - coins[ind] >= 0) {
15            long long int res = func(amount - coins[ind], coins, ind);
16            if (res != INT_MAX) {
17                opr1 = 1 + res;
18            }
19        }
20
21        // Choice 2: Skip the current coin (move to next index 'ind + 1')
22        opr2 = func(amount, coins, ind + 1);
23
24        return dp[ind][amount] = min(opr1, opr2);
25    }
26
27    int coinChange(vector<int>& coins, int amount) {
28        memset(dp, -1, sizeof(dp));
29        int ans = func(amount, coins, 0);
30        return ans == INT_MAX ? -1 : ans;
31    }
32};
33