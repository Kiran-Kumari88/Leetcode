class Solution {
public:
    int reverse(int x) {
        long long rev = 0;

        while (x != 0) {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }

        // Check if reversed number is within 32-bit int range
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;

        return rev;
    }
};