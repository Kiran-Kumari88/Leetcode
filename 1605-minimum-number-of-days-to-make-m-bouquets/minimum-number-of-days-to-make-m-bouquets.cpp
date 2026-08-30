class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
        int bouquets = 0, flowers = 0;
        for (int day : bloomDay) {
            if (day <= mid) { // bloom ho chuka h 
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } 
            else { // bloom ni hua abhi
                flowers = 0;
            }
            
            if (bouquets >= m)
                return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = (long long)m * k;
        if (bloomDay.size() < totalFlowers)
            return -1; // Not enough flowers

        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
