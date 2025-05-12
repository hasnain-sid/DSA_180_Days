class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        map<char, int> mp, kp;
        
        // Count characters in s1
        for (char c : s1) {
            mp[c]++;
        }

        int i = 0, j = 0;

        // Iterate over s2 with a sliding window
        while (i < s2.size()) {
            kp[s2[i]]++;  // Add the current character to the window
            
            // If the window size exceeds s1, remove the leftmost character
            if (i - j + 1 > s1.size()) {
                kp[s2[j]]--;
                if (kp[s2[j]] == 0) {
                    kp.erase(s2[j]);  // Remove if the count goes to 0
                }
                j++;  // Slide the window
            }

            // If the window size matches s1 and the maps are equal, return true
            if (i - j + 1 == s1.size() && mp == kp) {
                return true;
            }

            i++;  // Expand the window
        }

        return false;  // No permutation found
    }
};
