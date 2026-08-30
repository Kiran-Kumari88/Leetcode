class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while (start <= end) {
            int mid = start + (end - start) / 2; // mid speed se kha ri h 
            long long totalHr = 0;

            for (int i = 0; i < piles.size(); i++) {
                totalHr += ceil((double)piles[i] / mid); // equals to ceil(a/b)
            }

            if (totalHr <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};