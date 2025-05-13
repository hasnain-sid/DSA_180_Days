class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        long long int count[200] = {0};
           if(S.size() <=0)
           return 0;
           else if (S.size() == 1)
            return 1;
        int total = 0, first = 0, second = first + 1; // Initialize 'total' to 1
        count[S[0]]++;

        while (second < S.size()) {
            while (count[S[second]]) {
                count[S[first]]--;
                first++;
            }
            count[S[second]] = 1;
            total = max(total, second - first + 1);
            second++;
        }
        return total;
    }
};