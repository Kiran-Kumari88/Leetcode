class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0) return 0;

        int sum=1;
        int i = 1;
        while (i < n) { // flat
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) { // upwards slope
                peak += 1;
                sum += peak;
                i++;
            }

            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) { // downwards slope
                sum += down;
                i++;
                down += 1;
            }

            if (down >peak) {
                sum += (down - peak);
            }
        }
        return sum;
    }
};