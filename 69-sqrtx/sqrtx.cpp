class Solution {
public:
    int mySqrt(int n) {
        if (n == 0) return 0;

        int start = 1;
        int end = n;
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (1LL * mid * mid == n) {
                return mid;
            }
            else if (1LL * mid * mid < n) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};