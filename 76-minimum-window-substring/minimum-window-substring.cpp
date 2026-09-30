class Solution {
public:
    string minWindow(string s, string t) {

        int hash[256] = {0};

        int minLen = INT_MAX;
        int startIdx = -1;

        int l = 0;
        int r = 0;
        int cnt = 0;

        // Store frequency of characters in t
        for (int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }

        while (r < s.size()) {

            // Current character was required
            if (hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            // Window contains all characters of t
            while (cnt == t.size()) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                // Remove left character
                hash[s[l]]++;

                // Removed a required character
                if (hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};