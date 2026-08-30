class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++) {

            if (load + weights[i] <= cap) {
                load += weights[i];
            } else {
                days++;
                load = weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (findDays(weights, mid) <= days) { // mid=capacity
                ans=mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};