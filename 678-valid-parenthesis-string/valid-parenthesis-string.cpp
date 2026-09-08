class Solution {
public:
    bool checkValidString(string s) {
        int maxRange = 0;
        int minRange = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                maxRange++;
                minRange++;
            } else if (s[i] == ')') {
                maxRange--;
                minRange--;
            } else {
                maxRange++;
                minRange--;
            }
            if (minRange < 0)
                minRange = 0;
            if (maxRange < 0)
                return false;
        }
        return (minRange == 0);
    }
};