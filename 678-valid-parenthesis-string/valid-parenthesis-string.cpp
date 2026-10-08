class Solution {
public:
    bool checkValidString(string s) {
        //maxOpen → Maximum possible unmatched opening brackets (.
        //minOpen → Minimum possible unmatched opening brackets (.
        int maxOpen = 0;
        int minOpen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                maxOpen++;
                minOpen++;
            }
            else if (s[i] == ')') {
                maxOpen--;
                minOpen--;
            }
            else {  // '*'
                maxOpen++;
                minOpen--;
            }

            if (minOpen < 0)
                minOpen = 0;

            if (maxOpen < 0)
                return false;
        }

        return (minOpen == 0);
    }
};